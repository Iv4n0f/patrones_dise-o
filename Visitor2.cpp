#include <iostream>
#include <vector>

// Declaramos las interfaces
using namespace std;

class Visitor;

// Clase Element
class Element {
public:
    virtual void accept(Visitor* visitor) = 0;
};

// Subclases de Element
class ElementA : public Element {
public:
    void accept(Visitor* visitor) override;
};

class ElementB : public Element {
public:
    void accept(Visitor* visitor) override;
};

// Clase Visitor
class Visitor {
public:
    virtual void visitElementA(ElementA* a) = 0;
    virtual void visitElementB(ElementB* b) = 0;
};

// Implementación del método accept para ElementA y ElementB
void ElementA::accept(Visitor* visitor) {
    visitor->visitElementA(this);
}

void ElementB::accept(Visitor* visitor) {
    visitor->visitElementB(this);
}

// Subclases de Visitor
class Visitor1 : public Visitor {
public:
    void visitElementA(ElementA* a) override {
        cout << "Visitor1: Processing ElementA" << endl;
    }

    void visitElementB(ElementB* b) override {
        cout << "Visitor1: Processing ElementB" << endl;
    }
};

class Visitor2 : public Visitor {
public:
    void visitElementA(ElementA* a) override {
        cout << "Visitor2: Processing ElementA" << endl;
    }

    void visitElementB(ElementB* b) override {
        cout << "Visitor2: Processing ElementB" << endl;
    }
};

// Clase Cliente que usa el patrón Visitor
class Client {
public:
    void run() {
        vector<Element*> elements = { new ElementA(), new ElementB() };
        Visitor* v1 = new Visitor1();

        for (Element* elem : elements) {
            elem->accept(v1);
        }

        // Liberar memoria
        for (Element* elem : elements) {
            delete elem;
        }
        delete v1;
    }
};

int main() {
    Client client;
    client.run();
    return 0;
}
