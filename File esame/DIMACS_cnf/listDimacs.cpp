//lettura di file dimacs e riscrittura su una lista
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

struct node {
    int val;
    node* next;
};
typedef node* list;

struct Clause {
    list clausola;
    Clause* next;
};

void print_clauses(Clause *&head);

int main(int argc, char ** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number>" << std::endl;
        return 1;
    }

    std::ifstream cnffile(argv[1], std::ios::in);//apro file
    if (cnffile.fail()) {
        std::cerr << "Error opening file \"" << argv[1] << "\"" << std::endl;
        return 1;
    }

    int nclauses, nvariables;
    char prefix[100];
    char cnf[100];
    // Read p cnf nclauses nvariables
    cnffile >> prefix >> cnf >> nclauses >> nvariables;
    if (strcmp(prefix, "p") != 0 || strcmp(cnf, "cnf") != 0 || 
        nclauses <= 0 || nvariables <= 0) {
        std::cerr << "Error reading header of file \"" << argv[1] << "\"" << std::endl;
        cnffile.close();
        return 1;
    }

    // Allocate memory for the clauses array and terminator!
    Clause * head=NULL;
    Clause * last=NULL;
    

    //list * clauses = new list [nclauses+1];

    int i = 0;
    bool error = false;
    // Read the clauses and store them in the clauses array, 
    // if EOF is reached before having read the whole file, error is reported!
    for (i = 0; !error && i < nclauses && !cnffile.eof(); i++) {
        int n;
        // Read the number of literals in the clause
        cnffile >> n;
        //alloco la nuova clausola
        Clause *curClause=new Clause;
        curClause->next=NULL;
        //alloco il primo nodo della lista di letterali della clausola appena creata
        curClause->clausola= new node;
        list cur=curClause->clausola;
        // Read the literals
        for (int j = 0; j <n; j++) {
            if(!(cnffile >> cur->val)){
                error = true;
                break;
            }
            // If EOF is reached or a literal is greater 
            // than nvariables, or the literal is 0, error and stop reading
            if (abs(cur->val) > nvariables ||
                cur->val == 0) {
                    cout<<"il problema è nella riga "<<i<<" nel valore: "<<cur->val<<endl;
                error = true;
                break;
            }
            list newNode=new node;
            cur->next=newNode;
            cur=cur->next;
        }
        // If no error, add the terminator 0 to the clause
        if (!error) {
            cur->val = 0;
            cur->next=NULL;
        }
        if(head==NULL){
            head=curClause;
            last=curClause;
        }else{
            last->next=curClause;
            last=curClause; 
        }
    }
    //controllo che il file sia finito, altrimenti ho troppi dati
    char c;
    cnffile >> c;
    if (!cnffile.eof()) {
        error = true;
    }
    

    cnffile.close();

    // The number of read clauses must be equal to nclauses, otherwise error
    if (i != nclauses || error) {
        std::cerr << "Error reading file \"" << argv[1] << "\": eof or clause out of bound, or 0 encountered, or more clauses encountered" << std::endl;
        //dealloca le liste di liste
        Clause *curClause=head;
        while (curClause != nullptr) {
            // Dealloca la lista associata alla clausola corrente
            while (curClause->clausola != nullptr) {
                node* temp = curClause->clausola;
                curClause->clausola = curClause->clausola->next;
                delete temp;
            }
            // Passa alla clausola successiva deallocando quella corrente
            Clause* temp = curClause;
            curClause = curClause->next;
            delete temp;
        }
        return 1;
    }

    // Now we have the clauses in the clauses array, we print it
    print_clauses(head);

    // Now we can delete the clauses
    Clause *curClause=head;
    while (curClause != nullptr) {
        // Dealloca la lista associata alla clausola corrente
        while (curClause->clausola != nullptr) {
            node* temp = curClause->clausola;
            curClause->clausola = curClause->clausola->next;
            delete temp;
        }

        // Passa alla clausola successiva deallocando quella corrente
        Clause* temp = curClause;
        curClause = curClause->next;
        delete temp;
    }
}

void print_clauses(Clause *&head) {
    Clause * curClause=head;
    int max = 0;
    int c = 0;
    while (curClause != NULL) {
        list cur=curClause->clausola;
        while (cur->val != 0) {
            max = std::max(max, abs(cur->val));
            std::cout << cur->val << " ";
            cur=cur->next;
        }
        std::cout << "0" << std::endl;
        curClause=curClause->next;
        c++;
    }
    std::cout << "p cnf " << c << " " << max << std::endl;
}