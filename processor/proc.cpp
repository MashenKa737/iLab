#include"proc.h"

Arr_reg::Arr_reg():
    arr_reg_(0)
{
    arr_reg_.push_back("eax");
    arr_reg_.push_back("ebx");
    arr_reg_.push_back("ecx");
    arr_reg_.push_back("edx");
}

bool Command::mask_cmp(std::string str)
{
    int len = str.size();
    int i = 0, j = 0;
    while(j <= len){
        if(mask_[i] == '#'){
            i++;
            while(j<len && mask_[i] != str[j] && str[j] != ' ' && str[j] != '\t')
                j++;
        }
        if(mask_[i] != str[j])
            return 0;
        i++;
        j++;
    }
    return 1;
}

//*****
Jmp::Jmp():
    arr_jmp_(0)
{
    mask_ = "jmp #";
    arg_ = 1;
}

void Jmp::compile_command(const std::string str, std::vector<double> &arr)
{
    std::cout << "compile Jmp" << std::endl;
    std::istringstream str_read(str);
    label lab;
    str_read >> lab.name >> lab.name;
    lab.place = arr.size();
    arr_jmp_.push_back(lab);
    arr.push_back(-1);
}

void Jmp::make_jmp(std::vector<label> &arr_label, std::vector<double> &arr)
{
    int size_jmp = arr_jmp_.size();
    int size_lab = arr_label.size();
    int cur_jmp = 0, cur_lab = 0;

    for(cur_jmp = 0; cur_jmp < size_jmp; cur_jmp++){
        for(cur_lab = 0; cur_lab < size_lab; cur_lab++)
            if(arr_jmp_[cur_jmp].name == arr_label[cur_lab].name){
                arr[arr_jmp_[cur_jmp].place] = arr_label[cur_lab].place;
                break;
            }

        if(cur_lab == size_lab){
            std::cout << "label->jmp!!" << std::endl;
            assert(0);
        }
    }
}

//*****
Je::Je()
{
    mask_ = "je #";
    arg_ = 1;
}

//*****
Jne::Jne()
{
    mask_ = "jne #";
    arg_ = 1;
}

//*****
Jg::Jg()
{
    mask_ = "jg #";
    arg_ = 1;
}

//*****
Jng::Jng()
{
    mask_ = "jng #";
    arg_ = 1;
}

//*****
MovReg::MovReg()
{
    mask_ = "mov %# %#";
    arg_ = 2;
}

void MovReg::compile_command(const std::string str, std::vector<double> &arr)
{
    std::cout << "compile movreg" << std::endl;

    std::istringstream str_read(str);
    Arr_reg reg;
    int num_reg = reg.reg_size();
    int num = 0;
    std::string arg;

    //take out "mov"
    str_read.seekg(3, std::ios_base::cur);
    for(int i = 0; i < arg_; i++){
        //take out " %"
        str_read.seekg(2, std::ios_base::cur);
        str_read >> arg;
        for(num = 0; num < num_reg; num++)
            if(arg == reg.arr_reg(num)){
                arr.push_back(num);
                break;
            }

        if(num == num_reg){
            std::cout << "reg!" << std::endl;
            assert(0);
        }
    }
}

//*****
MovNum::MovNum()
{
    mask_ = "mov %# $#";
    arg_ = 2;
}

void MovNum::compile_command(const std::string str, std::vector<double> &arr)
{
    std::cout << "compile movnum" << std::endl;

    std::istringstream str_read(str);
    Arr_reg reg;
    int num_reg = reg.reg_size();
    int num = 0;
    double arg2 = 0;
    std::string arg1;

    //take out "mov %"
    str_read.seekg(5, std::ios_base::cur);
    str_read >> arg1;

    for(num = 0; num < num_reg; num++)
        if(arg1 == reg.arr_reg(num)){
            arr.push_back(num);
            break;
        }

    if(num == num_reg){
        std::cout << "reg!" << std::endl;
        assert(0);
    }

    //take out " $"
    str_read.seekg(2, std::ios_base::cur);
    str_read >> arg2;
    if(str_read.fail()){
        std::cout << "fail number!" << std::endl;
        assert(0);
    }
    else
        arr.push_back(arg2);
}

//*****
PushReg::PushReg()
{
    mask_ = "push %#";
    arg_ = 1;
}

void PushReg::compile_command(const std::string str, std::vector<double> &arr)
{
    std::cout << "compile PushReg" << std::endl;

    std::istringstream str_read(str);
    Arr_reg reg;
    int num_reg = reg.reg_size();
    int num = 0;
    std::string arg;

    //take out "push %"
    str_read.seekg(6, std::ios_base::cur);
    str_read >> arg;
    for(num = 0; num < num_reg; num++)
        if(arg == reg.arr_reg(num)){
            arr.push_back(num);
            break;
        }

    if(num == num_reg){
        std::cout << "reg!" << std::endl;
        assert(0);
        }
}

//*****
PushNum::PushNum()
{
    mask_ = "push $#";
    arg_ = 1;
}

void PushNum::compile_command(const std::string str, std::vector<double> &arr)
{
    std::cout << "compile pushnum" << std::endl;

    std::istringstream str_read(str);
    double arg;

    //take out "push $"
    str_read.seekg(6, std::ios_base::cur);
    str_read >> arg;
    if(str_read.fail()){
        std::cout << "fail number!" << std::endl;
        assert(0);
    }
    else
        arr.push_back(arg);
}

//*****
Cmp::Cmp()
{
    mask_ = "cmp";
    arg_ = 0;
}

//****
CPU::CPU():
    arr_command_(0), size_arr_(0),
    size_jmp_(5)//! size_jmp_ is number of commands which use array of label
{
    //*** block of commands that use array of label
    arr_command_.push_back(new Jmp[1]);
    arr_command_.push_back(new Je[1]);
    arr_command_.push_back(new Jne[1]);
    arr_command_.push_back(new Jg[1]);
    arr_command_.push_back(new Jng[1]);//size_jmp_ = 5
    //***
    arr_command_.push_back(new MovReg[1]);
    arr_command_.push_back(new MovNum[1]);
    arr_command_.push_back(new PushReg[1]);
    arr_command_.push_back(new PushNum[1]);
    arr_command_.push_back(new Cmp[1]);
    size_arr_ = arr_command_.size();
}

CPU::~CPU()
{
    int i = 0;
    for(i = 0; i < size_arr_; i++)
        delete(arr_command_[i]);
}

void delete_space(std::string &str)
{
    int size_str = str.size();
    int beg_sp = 0;
    for(beg_sp = 0; beg_sp < size_str && (str[beg_sp] == ' ' || str[beg_sp] == '\t'); beg_sp++);
    str = str.erase(0, beg_sp);
}

void get_label(std::vector<label> &arr_label, std::string &str1, int &cur_lab, int cur_put)
{
    std::string::size_type num;
    if((num = str1.find(":")) != std::string::npos){
        std::string str2 = str1.substr(0, num);

        for(int i = 0; i < cur_lab; i++)
            if(arr_label[i].name == str2){
                std::cout << "same label!" << std::endl;
                assert(0);
            }
        label lab;
        lab.name = str2;
        lab.place = cur_put;
        arr_label.push_back(lab);
        cur_lab++;

        str1 = str1.erase(0, num+1);
        delete_space(str1);
    }
}

void CPU::compile(std::string infile_name,std::string outfile_name)
{
    std::ifstream fin(infile_name.c_str());
    std::ofstream fout(outfile_name.c_str());

    std::vector<label> arr_label(0);
    std::vector<double> arr_put(0);
    std::string str1;
    int cur_put = 0, cur_lab = 0;

    while(std::getline(fin, str1, '\n')){
        int j = 0;
        //take label from string and delete space before and after it
        delete_space(str1);
        get_label(arr_label, str1, cur_lab, cur_put);
        //ignore empty string
        if(str1.size() == 0){
            continue;
        }
        //compile a command
        for(j = 0; j < size_arr_; j++){
            if(arr_command_[j]->mask_cmp(str1)){
                arr_put.push_back(j);
                cur_put += 1 + arr_command_[j]->com_arg();
                arr_command_[j]->compile_command(str1, arr_put);
                break;
            }
        }
        if(j == size_arr_){
            std::cout << "no command!" << std::endl;
            assert(0);
        }
    }
    //! link between array of labels and they place in code:
    //! function "make_jmp" in class "Jmp". Without this command Jmp has not true argument (-1) after compiling.
    for(int i = 0; i < size_jmp_; i++)
        ((Jmp*)arr_command_[i])->make_jmp(arr_label, arr_put);

    for(int i = 0; i < cur_put; i++)
        fout << arr_put[i] << std::endl;

    fin.close();
    fout.close();
}

void CPU::run(std::string infile_name)
{
    std::ifstream fin(infile_name.c_str());
    double num = 0;
    std::vector<double> arr_get(0);
    CPU_struct cpu;

    fin >> num;
    while(!fin.eof()){
        arr_get.push_back(num);
        fin >> num;
    }
    int size_get = arr_get.size();

    for(int cur = 0; cur < size_get; cur++){
        if((int)arr_get[cur] >= size_arr_){
            std::cout << "!!! run abort !!!" << std::endl;
            assert(0);
        }
        arr_command_[(int)arr_get[cur]]->run_command(arr_get, cur, cpu);
        cur += arr_command_[(int)arr_get[cur]]->com_arg();
    }
    fin.close();
}
