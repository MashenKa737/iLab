#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include"CStack.h"

#include<assert.h>

class CPU_struct
{
public:
    CPU_struct():
        stack_val(1) { }
    double reg_arr[4];
    bool fl;
    CStack<double> stack_val;
};

struct label
{
    std::string name;
    int place;
};

class Arr_reg
{
public:
    Arr_reg();
    std::string arr_reg(int i) {return arr_reg_[i];}
    int reg_size() {return arr_reg_.size();}
private:
    std::vector<std::string> arr_reg_;
};

class Command
{
public:
    Command() { }
    virtual ~Command() { }
    bool mask_cmp(std::string str);
    int com_arg() {return arg_;}
    virtual void compile_command(std::string str, std::vector<double> &arr) = 0;
    virtual void run_command(std::vector<double> &arr, int &cur, CPU_struct &cpu) const = 0;
protected:
    std::string mask_;
    int arg_;
};

class CPU
{
public:
    CPU();
    ~CPU();
    void compile(std::string infile_name,std::string outfile_name);
    void run(std::string infile_name);
private:
    std::vector<Command*> arr_command_;
    int size_arr_;
    int size_jmp_;
};

class Jmp: public Command
{
public:
    Jmp();
    ~Jmp() { }
    void compile_command(const std::string str, std::vector<double> &arr);
    virtual void run_command(std::vector<double> &arr, int &cur, CPU_struct &cpu) const
    { std::cout << "run jmp" << std::endl; }
    void make_jmp(std::vector<label> &arr_label, std::vector<double> &arr);
private:
    std::vector<label> arr_jmp_;
};

class Je: public Jmp
{
public:
    Je();
    ~Je() { }
    void run_command(std::vector<double> &arr, int &cur, CPU_struct &cpu) const
    { std::cout << "run je" << std::endl; }
};

class Jne: public Jmp
{
public:
    Jne();
    ~Jne() { }
    void run_command(std::vector<double> &arr, int &cur, CPU_struct &cpu) const
    { std::cout << "run jne" << std::endl; }
};

class Jg: public Jmp
{
public:
    Jg();
    ~Jg() { }
    void run_command(std::vector<double> &arr, int &cur, CPU_struct &cpu) const
    { std::cout << "run jg" << std::endl; }
};

class Jng: public Jmp
{
public:
    Jng();
    ~Jng() { }
    void run_command(std::vector<double> &arr, int &cur, CPU_struct &cpu) const
    { std::cout << "run jng" << std::endl; }
};

class MovReg: public Command
{
public:
    MovReg();
    ~MovReg() { }
    void compile_command(const std::string str, std::vector<double> &arr);
    void run_command(std::vector<double> &arr, int &cur, CPU_struct &cpu)
    const { std::cout << "run movreg" << std::endl;}
};

class MovNum: public Command
{
public:
    MovNum();
    ~MovNum() { }
    void compile_command(const std::string str, std::vector<double> &arr);
    void run_command(std::vector<double> &arr, int &cur, CPU_struct &cpu) const
    { std::cout << "run movnum" << std::endl;}
};

class Cmp: public Command
{
public:
    Cmp();
    ~Cmp() { }
    void compile_command(const std::string str, std::vector<double> &arr){std::cout << "compile cmp" << std::endl; }
    void run_command(std::vector<double> &arr, int &cur, CPU_struct &cpu) const
    { std::cout << "run cmp" << std::endl;}
};

class PushReg: public Command
{
    public:
    PushReg();
    ~PushReg() { }
    void compile_command(const std::string str, std::vector<double> &arr);
    void run_command(std::vector<double> &arr, int &cur, CPU_struct &cpu) const
    { std::cout << "run pushreg" << std::endl;}
};

class PushNum: public Command
{
    public:
    PushNum();
    ~PushNum() { }
    void compile_command(const std::string str, std::vector<double> &arr);
    void run_command(std::vector<double> &arr, int &cur, CPU_struct &cpu) const
    { std::cout << "run pushnum" << std::endl;}
};
