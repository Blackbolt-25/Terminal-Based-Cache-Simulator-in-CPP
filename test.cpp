// #include <iostream>
// #include <vector>
// #include <string>
//
// // Define a custom struct to hold integer and string fields
// struct Data {
//     int intField1;
//     int intField2;
//     std::string stringField1;
//     std::string stringField2;
// };
//
// int main() {
//     // Declare a vector of Data structs
//     std::vector<Data> dataVector;
//
//     // Add elements to the vector
//     Data data1 = {1, 2, "foo", "bar"};
//     Data data2 = {3, 4, "baz", "qux"};
//     dataVector.push_back(data1);
//     dataVector.push_back(data2);
//
//     // Access elements of the vector
//     std::cout << "Vector size: " << dataVector.size() << std::endl;
//     for (const auto& data : dataVector) {
//         std::cout << "Integers: " << data.intField1 << ", " << data.intField2 << std::endl;
//         std::cout << "Strings: " << data.stringField1 << ", " << data.stringField2 << std::endl;
//     }
//
//     return 0;
// }

// #include<iostream>
// #include<string>
// #include<unordered_map>
//
// using namespace std;
//
// struct data{
//   int data;
//   string h;
// };
//
// int main()
// {
//   unordered_map <int,data> temp;
//   temp[1].data = 2;
//   temp[1].h = "hel";
//   if(temp[1].data != 0)
//     cout<<temp[1].h;
//   else
//     cout<<"No";
// }


         
         
#include <iostream>
#include <iomanip>

using namespace std;


string to_binary(int addr,int n)
{
  string temp = "";
  while(addr)
  {
    temp = to_string(addr%2) + temp;
    addr = addr/2;
  }
  for(int i = temp.size();i<n;i++)
    temp = "0" + temp;
  return temp;
}


void printStats()
{
  cout<<"Cache Table:-\n\n";
  int Capacity_Cache_Memory = 16;
  int Block_Size = 2;
  cout << setw(61) << setfill('-') << "" << "\n";
  cout << setfill(' ');
  cout<<"|"<<setw(10)<<setfill(' ')<<"Index"<<setw(10)<<"|"<<setw(10)<<setfill(' ')<<"Valid Bit"<<setw(10)<<"|"<<setw(10)<<setfill(' ')<<"Tag"<<setw(10)<<setfill(' ')<<"|"<<setw(10)<<setfill(' ')<<"Word"<<setw(10)<<"|"<<endl;
  int binary_bits = log2(Capacity_Cache_Memory)/log2(Block_Size);
  for(int i=0;i<log2(Capacity_Cache_Memory)/log2(Block_Size);i++)
    cout<<"|"<<setw(10)<<setfill(' ')<<"Index"<<setw(10)<<"|"<<setw(10)<<setfill(' ')<<"Valid Bit"<<setw(10)<<"|"<<setw(10)<<setfill(' ')<<"Tag"<<setw(10)<<setfill(' ')<<"|"<<setw(10)<<setfill(' ')<<"Word"<<setw(10)<<"|"<<endl;

  cout << setw(61) << setfill('-') << "" << "\n";
  cout << setfill(' ');

  cout<<"\n\n";
}

int main() {
  //
  // cout<<"Binary Address format:-\n";
  // cout << setw(61) << setfill('-') << "" << "\n";
  // cout << setfill(' ');
  // cout<<"|"<<setw(10)<<setfill(' ')<<"Tag"<<setw(10)<<"|"<<setw(10)<<setfill(' ')<<"Index"<<setw(10)<<"|"<<setw(10)<<setfill(' ')<<"Word"<<setw(10)<<setfill(' ')<<"|"<<endl;
  // cout << setw(61) << setfill('-') << "" << "\n";
  // cout << setfill(' ');
  printStats(); 


  
}

