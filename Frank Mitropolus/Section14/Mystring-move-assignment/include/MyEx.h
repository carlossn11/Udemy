#ifndef MYEX_H_
#define MYEX_H_

class Mystring {
 public:
  // Constuctors & Destructors
  Mystring();
  Mystring(const char* str);
  Mystring(const Mystring &rhs);
  Mystring(Mystring &&rhs);
  ~Mystring();

  // Overloaded Operators
  void operator=(const Mystring &rhs);
  void operator=(Mystring &&rhs);
  Mystring operator-() const ;
  bool operator==(const Mystring &rhs) const {
    return (std::strcmp(this->str, rhs.str) == 0);
  }
  Mystring operator+(const Mystring &rhs) const;

  // Class Public Methods
  void displayStr();

  // Friend Methods
  friend std::istream &operator>>(std::istream &is, Mystring &rhs);

 private:
  char* str;
};
#endif // MYEX_H_