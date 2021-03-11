#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
int main()
{
    string path = "";
    string opath = "";
    string mode;
    cout << "enter path: ";
    getline(cin, path);
    cout << "enter output path: ";
    getline(cin, opath);
    cout << "1- Encrypt\n2- Encrypt using key\n3- Decrypt\n4- Decrypt using key\n\nenter mode: ";
    getline(cin, mode);
    int _index = 1;
    int _max_index = 5;
    if (mode == "1")
    {
        fstream fin,fout;
        fin.open(path, ios::in | ios::binary);
        fout.open(opath,ios::out | ios::binary);
        if (!fin)
        {
            cout << "failed to open file!";
        }
        else
        {
            char ch;
            while (!fin.eof())
            {
                if (_index >= _max_index)   _index = 1;
                fin >> noskipws >> ch;
                ch = (char)(ch + _index);
                fout << ch;
                _index++;
            }
            fin.close();
            fout.close();
            cout << "Encrypted!";
        }
    }
    else if (mode == "2"){
        string _key;
        int _kindex = 0;
        cout << "enter key: ";
        getline(cin,_key);
        fstream fin,fout;
        fin.open(path, ios::in | ios::binary);
        fout.open(opath,ios::out | ios::binary);
        if (!fin)
        {
            cout << "failed to open file!";
        }
        else
        {
            char ch;
            while (!fin.eof())
            {
                if (_index >= _max_index)   _index = 1;
                if (_kindex == _key.length() - 1)    _kindex = 0;
                fin >> noskipws >> ch;
                ch = (char)(ch + _index + _key[_kindex]);
                fout << ch;
                _index++;
                _kindex++;
            }
            fin.close();
            fout.close();
            cout << "Encrypted!";
        }
    }
    else if (mode == "3")
    {
        fstream fin,fout;
        fin.open(path, ios::in | ios::binary);
        fout.open(opath,ios::out | ios::binary);
        if (!fin)
        {
            cout << "failed to open file!";
        }
        else
        {
            char ch;
            while (!fin.eof())
            {
                if (_index >= _max_index)   _index = 1;
                fin >> noskipws >> ch;
                ch = (char)(ch - _index);
                fout << ch;
                _index++;
            }
            fin.close();
            fout.close();
            cout << "Decrypted!";
        }
    }
    else if (mode == "4"){
        string _key;
        int _kindex = 0;
        cout << "enter key: ";
        getline(cin,_key);
        fstream fin,fout;
        fin.open(path, ios::in | ios::binary);
        fout.open(opath,ios::out | ios::binary);
        if (!fin)
        {
            cout << "failed to open file!";
        }
        else
        {
            char ch;
            while (!fin.eof())
            {
                if (_index >= _max_index)   _index = 1;
                if (_kindex == _key.length() - 1)    _kindex = 0;
                fin >> noskipws >> ch;
                ch = (char)(ch - _index - _key[_kindex]);
                fout << ch;
                _index++;
                _kindex++;
            }
            fin.close();
            fout.close();
            cout << "Decrypted!";
        }
    }
    else
    {
        cout << "'" << mode << "' is not a valid mode !";
        cin.get();
        exit(0);
    }
    return 0;
}