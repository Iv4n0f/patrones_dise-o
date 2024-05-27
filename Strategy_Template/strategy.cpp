#include <iostream>

// Interfaz para las estrategias de cálculo de impuestos
class TaxStrategy {
public:
  virtual ~TaxStrategy() = default;
  virtual double calculateTax(double amount) const = 0;
};

// Estrategia concreta
class BasicTax : public TaxStrategy {
public:
  double calculateTax(double amount) const override { return amount * 0.1; }
};

// Estrategia concreta
class LuxuryTax : public TaxStrategy {
public:
  double calculateTax(double amount) const override { return amount * 0.2; }
};

// Estrategia concreta
class ExemptTax : public TaxStrategy {
public:
  double calculateTax(double amount) const override { return 0.0; }
};

// Contexto
class Product {
private:
  double price;
  TaxStrategy *taxStrategy;

public:
  Product(double price, TaxStrategy *strategy)
      : price(price), taxStrategy(strategy) {}

  void setTaxStrategy(TaxStrategy *strategy) { taxStrategy = strategy; }

  double calculateTotalPrice() const {
    double tax = taxStrategy->calculateTax(price);
    return price + tax;
  }
};

int main() {
  BasicTax basicTax;
  LuxuryTax luxuryTax;
  ExemptTax exemptTax;

  Product basicProduct(100.0, &basicTax);
  Product luxuryProduct(1000.0, &luxuryTax);
  Product exemptProduct(500.0, &exemptTax);

  std::cout << "Basic Product Total Price: "
            << basicProduct.calculateTotalPrice() << std::endl;
  std::cout << "Luxury Product Total Price: "
            << luxuryProduct.calculateTotalPrice() << std::endl;
  std::cout << "Exempt Product Total Price: "
            << exemptProduct.calculateTotalPrice() << std::endl;

  // Cambiar la estrategia de impuestos para un producto
  exemptProduct.setTaxStrategy(&basicTax);
  std::cout << "Exempt Product Total Price (after strategy change): "
            << exemptProduct.calculateTotalPrice() << std::endl;

  return 0;
}
