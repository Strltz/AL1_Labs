// Lab6_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct ProgramCryptoSecurity
{
    std::string nameDeveloper;
    int numberVersion;
    std::string algorithmName;
    std::string licenseFSB;
};

int main(int argc, char* argv[])
{
    if (argc != 4) {
        std::cerr << "Error: enter 4 parameters";
        return 32202;
    }
    std::string rd_wr_cl = argv[1];
    std::string bnr_txt = argv[2];
    std::string file_name = argv[3];
    if (bnr_txt == "text") {
        if (rd_wr_cl == "write") {
            std::ofstream for_write(file_name, std::ios::app);
            size_t count_instr;
            std::cout << "Enter count of instruments\n";
            std::cin >> count_instr;
            std::vector<ProgramCryptoSecurity> instruments;
            for (size_t i = 0; i < count_instr; ++i) {
                ProgramCryptoSecurity instrument_smthg;
                std::cout << "Enter nameDeveloper, numberVersion, algorithmName, licenseFSB" << std::endl;
                std::cin >> instrument_smthg.nameDeveloper;
                std::cin >> instrument_smthg.numberVersion;
                std::cin >> instrument_smthg.algorithmName;
                std::cin >> instrument_smthg.licenseFSB;
                instruments.push_back(instrument_smthg);
            }
            for (size_t i = 0; i < instruments.size(); ++i) {
                for_write << instruments[i].nameDeveloper << ' '
                    << instruments[i].numberVersion << ' '
                    << instruments[i].algorithmName << ' '
                    << instruments[i].licenseFSB << std::endl;
            }
            for_write.close();
        }
        else if (rd_wr_cl == "read") {
            std::ifstream for_read(file_name, std::ios::in);
            std::string for_enter;
            while (std::getline(for_read, for_enter)) {
                std::cout << for_enter << std::endl;
            }
            for_read.close();
        }
        else if (rd_wr_cl == "clear") {
            std::ofstream for_write(file_name, std::ios::out | std::ios::trunc);
            std::cout << "File has been cleared\n";
            for_write.close();
        }
        else {
            std::cout << "Error: enter \"write\", \"read\" or \"clear\"";
        }
    }
    else {
        if (rd_wr_cl == "write") {
            std::ofstream for_write(file_name, std::ios::binary | std::ios::app);
            size_t count_instr;
            std::cout << "Enter count of instruments\n";
            std::cin >> count_instr;
            for (size_t i = 0; i < count_instr; ++i) {
                ProgramCryptoSecurity instrument_smthg;
                std::cout << "Enter nameDeveloper, numberVersion, algorithmName, licenseFSB" << std::endl;
                std::cin >> instrument_smthg.nameDeveloper;
                std::cin >> instrument_smthg.numberVersion;
                std::cin >> instrument_smthg.algorithmName;
                std::cin >> instrument_smthg.licenseFSB;
                for_write.write((char*)&instrument_smthg, sizeof(instrument_smthg));
            }
            for_write.close();
        }
        else if (rd_wr_cl == "read") {
            std::ifstream for_read(file_name, std::ios::binary);
            ProgramCryptoSecurity instrument_smthg;
            std::vector<ProgramCryptoSecurity> v;
            while (!for_read.eof()) {
                for_read.read((char*)&instrument_smthg, sizeof(instrument_smthg));
                v.push_back(instrument_smthg);
            }
            for (size_t i = 0; i < v.size() - 1; ++i) {
                std::cout << v[i].nameDeveloper << ' '
                << v[i].numberVersion << ' ' << v[i].algorithmName << ' '
                << v[i].licenseFSB << std::endl;
            }
            std::cout << std::endl;
            for_read.close();
        }
        else if (rd_wr_cl == "clear") {
            std::ofstream for_write(file_name, std::ios::binary);
            std::cout << "File has been cleared\n";
            for_write.close();
        }
        else {
            std::cout << "Error: enter \"write\", \"read\" or \"clear\"";
        }
    }
}
