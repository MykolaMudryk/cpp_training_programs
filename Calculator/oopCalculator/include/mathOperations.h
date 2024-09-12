#ifndef mathOperations_h
#define mathOperations_h

#include <string>
#include <utility>

class SetOperation{
private:
    std::string operation;
public:
    void setOperation();
    std::string getOperation() const;
};

class SetOperands{
private:
    int num1, num2;
public:
    void setOperands();
    std::pair<int, int> getOperands() const;
};

class ExecuteOperations{
private:
    int result;
public:
    void performOperations(const SetOperands &operands, const SetOperation &operation);
};

class IMathOperations {
public:
    virtual int execute(int num1, int num2) = 0;
    virtual ~IMathOperations() = default;
};

class Addition : public IMathOperations {
public:
    int execute(int num1, int num2) override;
};

class Subtraction : public IMathOperations {
public:
    int execute(int num1, int num2) override;
};

class Multiplication : public IMathOperations {
public:
    int execute(int num1, int num2) override;
};

class Division : public IMathOperations {
public:
    int execute(int num1, int num2) override;
};

#endif
