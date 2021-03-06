#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "person.cpp"
#include <vector>

using namespace std;

void readData(vector<Person> &workers);
void getCompanies(vector<Person> &workers, vector<string> &names);
void printHighestPaid(vector<Person> &workers);
void separateAndSave(vector<Person> &workers, vector<string> &names);

int main()
{
    vector<Person> individual;
    vector<string> companyNames;
    readData(individual);
    getCompanies(individual, companyNames);
    printHighestPaid(individual);
    separateAndSave(individual, companyNames);
}

void readData(vector <Person> &workers)
{
    Person local;
    string firstnames;
    string lastnames;
    int id;
    string companies;
    float rates;
    float numofHours;
    ifstream newFile;
    newFile.open("input.txt");
    while(newFile >> firstnames >> lastnames >> id >> companies >> numofHours >> rates)
    {
        local.setFirstName(firstnames);
        local.setLastName(lastnames);
        local.setEmployeeId(id);
        local.setCompanyName(companies);
        local.setHoursWorked(numofHours);
        local.setPayRate(rates);
        /*cout << local.getFirstName() << endl;
        cout << local.getLastName() << endl;
        cout << local.getEmployeeId() << endl;
        cout << local.getCompanyName() << endl;
        cout << local.getHoursWorked() << endl;
        cout << local.getPayRate() << endl;*/
        workers.push_back(local);
    }
    
    newFile.close();
}


void getCompanies(vector<Person> &workers, vector<string> &names)
{
    string tempString;
    for(int i = 0; i < workers.size(); i++)
    {
        tempString = workers.at(i).getCompanyName();
        names.push_back(tempString);
       
    }
    
   
    
}
void printHighestPaid(vector<Person> &workers)
{
    string name, compName;
    int idNum = 0;
    float totalPay = 0.0;
    //float highest;
    
    
    for(int i = 0; i < workers.size(); i++)
    {
        
        //if(highest < workers.at(i).totalPay())
        if(totalPay < workers.at(i).totalPay())
        {
            totalPay = workers.at(i).totalPay();
            name = workers.at(i).fullName();
            idNum = workers.at(i).getEmployeeId();
            compName = workers.at(i).getCompanyName();
        }
         
        
       /* highest = workers.at(i).totalPay();
        if(totalPay > highest)
        {
            //highest = totalPay;
            //totalPay = workers.at(i).totalPay();
            name = workers.at(i).fullName();
            idNum = workers.at(i).getEmployeeId();
            compName = workers.at(i).getCompanyName();
        }*/
    }
    
    
    
    
    cout << "Highest paid: " <<  name  << endl;
    cout << "Employee ID: " << idNum  << endl;
    cout << "Employer: " <<  compName  << endl;
    cout << "Total Pay: $" <<  totalPay << endl;
    
}
void separateAndSave(vector<Person> &workers, vector<string> &names)
{
    string employeeCompanies;
    //string fullNam;
    string fnames;
    string lnames;
    int idNumber;
    string comp;
    float totalAmount = 0.0;
    float totals = 0.0;
    
    /*for(int i = 0; i< names.size(); i++)
    {
        cout << names[i] << endl;
    }*/
    
    
    
    
    for(int i = 0; i < names.size(); i++)
    {
        totals = 0.0;
        string listCompany;
        listCompany = names.at(i);
        ofstream exitFile;
        exitFile.open(listCompany + ".txt");
        
        for(int j = 0; j < workers.size(); j++)
        {
            
            employeeCompanies = workers.at(j).getCompanyName();
            if(employeeCompanies == listCompany)
            {
                //fullNam = workers.at(j).fullName();
                fnames = workers.at(j).getFirstName();
                lnames = workers.at(j).getLastName();
                idNumber = workers.at(j).getEmployeeId();
                comp = workers.at(j).getCompanyName();
                totalAmount = workers.at(j).totalPay();
                //exitFile << left << setw(20) << fullNam << " " << idNumber << " " << comp << " $" << totalAmount << endl;
                exitFile <<  fixed << setprecision(2);
                //exitFile << setw(10) << left << fnames << setw(6) << left << lnames << right << setw(6) << idNumber << " " << right << setw(2) << comp << setw(2) << " $" << totalAmount << endl;
                exitFile << left << setw(10) << fnames << setw(10) << lnames << " "  << right << setw(10) << idNumber << " " << right << setw(6) << comp << right << setw(5) << " $" << totalAmount << endl;
                 totals += workers.at(j).totalPay();
            }
            
            //totals += workers.at(i).totalPay();
            
           
        }
        
        exitFile << "Total: " << "$" << totals << endl;
    }
    
    
}


