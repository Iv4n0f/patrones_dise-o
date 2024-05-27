#include <iostream>

using namespace std;

/**
 * La Clase Abstracta define un método plantilla que contiene un esqueleto de algún
 * algoritmo, compuesto por llamadas a operaciones primitivas (usualmente) abstractas.
 *
 * Las subclases concretas deben implementar estas operaciones, pero dejar el método
 * plantilla intacto.
 */
class AbstractClass {
  /**
   * El método plantilla define el esqueleto de un algoritmo.
   */
 public:
  void TemplateMethod() const {
    this->BaseOperation1();
    this->RequiredOperations1();
    this->BaseOperation2();
    this->Hook1();
    this->RequiredOperation2();
    this->BaseOperation3();
    this->Hook2();
  }
  /**
   * Estas operaciones ya tienen implementaciones.
   */
 protected:
  void BaseOperation1() const {
    cout << "AbstractClass dice: Estoy haciendo la mayor parte del trabajo\n";
  }
  void BaseOperation2() const {
    cout << "AbstractClass dice: Pero dejo que las subclases sobrescriban algunas operaciones\n";
  }
  void BaseOperation3() const {
    cout << "AbstractClass dice: Pero de todas formas estoy haciendo la mayor parte del trabajo\n";
  }
  /**
   * Estas operaciones deben ser implementadas en las subclases.
   */
  virtual void RequiredOperations1() const = 0;
  virtual void RequiredOperation2() const = 0;
  /**
   * Estos son "ganchos". Las subclases pueden sobrescribirlos, pero no es obligatorio
   * ya que los ganchos ya tienen una implementación predeterminada (pero vacía). Los ganchos
   * proporcionan puntos de extensión adicionales en algunos lugares cruciales del
   * algoritmo.
   */
  virtual void Hook1() const {}
  virtual void Hook2() const {}
};
/**
 * Las clases concretas deben implementar todas las operaciones abstractas de la clase base.
 * También pueden sobrescribir algunas operaciones con una implementación predeterminada.
 */
class ConcreteClass1 : public AbstractClass {
 protected:
  void RequiredOperations1() const override {
    cout << "ConcreteClass1 dice: Implementada la Operación1\n";
  }
  void RequiredOperation2() const override {
    cout << "ConcreteClass1 dice: Implementada la Operación2\n";
  }
};
/**
 * Usualmente, las clases concretas sobrescriben solo una fracción de las operaciones de la clase base.
 */
class ConcreteClass2 : public AbstractClass {
 protected:
  void RequiredOperations1() const override {
    cout << "ConcreteClass2 dice: Implementada la Operación1\n";
  }
  void RequiredOperation2() const override {
    cout << "ConcreteClass2 dice: Implementada la Operación2\n";
  }
  void Hook1() const override {
    cout << "ConcreteClass2 dice: Sobrescrito el Hook1\n";
  }
};
/**
 * El código cliente llama al método plantilla para ejecutar el algoritmo. El
 * código cliente no tiene que conocer la clase concreta del objeto con el que trabaja,
 * siempre que funcione con objetos a través de la interfaz de su clase base.
 */
void ClientCode(AbstractClass *class_) {
  // ...
  class_->TemplateMethod();
  // ...
}

int main() {
  cout << "El mismo código cliente puede trabajar con diferentes subclases:\n";
  ConcreteClass1 *concreteClass1 = new ConcreteClass1;
  ClientCode(concreteClass1);
  cout << "\n";
  cout << "El mismo código cliente puede trabajar con diferentes subclases:\n";
  ConcreteClass2 *concreteClass2 = new ConcreteClass2;
  ClientCode(concreteClass2);
  delete concreteClass1;
  delete concreteClass2;
  return 0;
}
