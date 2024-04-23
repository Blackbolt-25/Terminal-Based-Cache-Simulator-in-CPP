#include<iostream>
#include<cmath>
#include<unordered_map>
#include<string>
#include<utility>
#include<iomanip>

using namespace std;

int add(int a,int b);
void logo();

struct Data{
  int valid_bit;
  string tag;
  string block_word;
};

class Cache{
  private:
    int Main_Memory_Size;
    int Capacity_Cache_Memory;
    int Block_Size;
    string current_addr;
    int hits;
    int misses;
    unordered_map <string, Data> Cache_table;
  public:
    Cache(int M_M_S,int C_C_M,int B_S):Main_Memory_Size(M_M_S),Capacity_Cache_Memory(C_C_M),Block_Size(B_S),hits(0),misses(0){
      int bit_block_size = log2(Block_Size);
      int bit_index = log2(Capacity_Cache_Memory)/log2(Block_Size);
      int bit_tag = log2(Main_Memory_Size) - bit_block_size - bit_index;
      init(bit_tag,bit_block_size);
    } //Constructor to give all the variables their values.

    void init(int tag_bits,int block_bits)
    {
      int rows = pow(2,log2(Capacity_Cache_Memory)/log2(Block_Size));
      string temp_tag = "_";
      for(int i=1;i<tag_bits;i++)
        temp_tag= temp_tag + "_";
      string block_word = "_";
      for(int i=1;i<block_bits;i++)
        block_word= block_word + "_";
      Data temp = {0,temp_tag,block_word};
      for(int i=0;i<rows;i++)
        Cache_table[to_binary(i,block_bits)] = temp;
    }

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


    void accessMemory(int addr)
    {
      string binary_addr = to_binary(addr,log2(Main_Memory_Size));
      current_addr = binary_addr;
      int bit_block_size = log2(Block_Size);
      int bit_index = log2(Capacity_Cache_Memory)/log2(Block_Size);
      int bit_tag = log2(Capacity_Cache_Memory) - bit_block_size - bit_index;

      string word = binary_addr.substr(binary_addr.size() - bit_block_size);
      string index = binary_addr.substr(binary_addr.size() - bit_block_size - bit_index, (binary_addr.size() - bit_block_size) - (binary_addr.size() - bit_block_size - bit_index));
      string tag = binary_addr.substr(0,binary_addr.size() - bit_block_size - bit_index);
      
      if(Cache_table[index].valid_bit != 0)
      {
        if(Cache_table[index].tag == tag)
        {
          hits++;
          printStats();
          printStats(addr,1,word,index,tag);
        }
        else
        {
          printStats();
          Data temp = {1,tag,word};
          Cache_table[index] = temp;
          misses++;
          printStats(addr,2,word,index,tag);
          cout<<"Cache Miss\n";
        }
      }
      else
      {
        printStats();
        Data temp = {1,tag,word};
        Cache_table[index] = temp;
        misses++;
        printStats(addr,3,word,index,tag);
        cout<<"Cache Miss\n";
      }
    }

    void printStats()
    {
      cout<<"Cache Table:-\n\n";
      cout << setw(61) << setfill('-') << "" << "\n";
      cout << setfill(' ');
      cout<<"|"<<setw(10)<<setfill(' ')<<"Index"<<setw(10)<<"|"<<setw(10)<<setfill(' ')<<"Valid Bit"<<setw(10)<<"|"<<setw(10)<<setfill(' ')<<"Tag"<<setw(10)<<setfill(' ')<<"|"<<setw(10)<<setfill(' ')<<"Word"<<setw(10)<<"|"<<endl;
      cout << setw(61) << setfill('-') << "" << "\n";
      cout << setfill(' ');
      int block_bit = log2(Block_Size);
      int binary_bits = log2(Capacity_Cache_Memory)/log2(Block_Size);
      int tag_bits = log2(Main_Memory_Size) - block_bit - binary_bits;
      for(int i=0;i<pow(2,log2(Capacity_Cache_Memory)/log2(Block_Size));i++)
        cout<<"|"<<setw(10)<<setfill(' ')<<i<<setw(10)<<"|"<<setw(10)<<setfill(' ')<<Cache_table[to_binary(i,binary_bits)].valid_bit<<setw(10)<<"|"<<setw(10)<<setfill(' ')<<Cache_table[to_binary(i,binary_bits)].tag<<setw(10)<<setfill(' ')<<"|"<<setw(10)<<setfill(' ')<<Cache_table[to_binary(i,binary_bits)].block_word<<setw(10)<<"|"<<endl;

      cout << setw(61) << setfill('-') << "" << "\n";
      cout << setfill(' ');

      cout<<"\n\n";
    }

    void printStats(int addr,int check,string word,string index, string tag)
    {
      cout<<"Memory Address accessed:- "<<addr<<" "<<"("<<current_addr<<")\n\n";

      cout<<"Binary Address format:-\n";
      cout << setw(61) << setfill('-') << "" << "\n";
      cout << setfill(' ');
      cout<<"|"<<setw(10)<<setfill(' ')<<"Tag"<<setw(10)<<"|"<<setw(10)<<setfill(' ')<<"Index"<<setw(10)<<"|"<<setw(10)<<setfill(' ')<<"Word"<<setw(10)<<setfill(' ')<<"|"<<endl;
      cout<<"|"<<setw(10)<<setfill(' ')<<tag<<setw(10)<<"|"<<setw(10)<<setfill(' ')<<index<<setw(10)<<"|"<<setw(10)<<setfill(' ')<<word<<setw(10)<<setfill(' ')<<"|"<<endl;
      cout << setw(61) << setfill('-') << "" << "\n";
      cout << setfill(' ');

      cout<<"New Cache Table:-\n\n";
      cout << setw(61) << setfill('-') << "" << "\n";
      cout << setfill(' ');
      cout<<"|"<<setw(10)<<setfill(' ')<<"Index"<<setw(10)<<"|"<<setw(10)<<setfill(' ')<<"Valid Bit"<<setw(10)<<"|"<<setw(10)<<setfill(' ')<<"Tag"<<setw(10)<<setfill(' ')<<"|"<<setw(10)<<setfill(' ')<<"Word"<<setw(10)<<"|"<<endl;
      int block_bit = log2(Block_Size);
      int binary_bits = log2(Capacity_Cache_Memory)/log2(Block_Size);
      int tag_bits = log2(Main_Memory_Size) - block_bit - binary_bits;
      cout << setw(61) << setfill('-') << "" << "\n";
      cout << setfill(' ');
      for(int i=0;i<pow(2,log2(Capacity_Cache_Memory)/log2(Block_Size));i++)
        cout<<"|"<<setw(10)<<setfill(' ')<<i<<setw(10)<<"|"<<setw(10)<<setfill(' ')<<Cache_table[to_binary(i,binary_bits)].valid_bit<<setw(10)<<"|"<<setw(10)<<setfill(' ')<<Cache_table[to_binary(i,binary_bits)].tag<<setw(10)<<setfill(' ')<<"|"<<setw(10)<<setfill(' ')<<Cache_table[to_binary(i,binary_bits)].block_word<<setw(10)<<"|"<<endl;

      cout << setw(61) << setfill('-') << "" << "\n";
      cout << setfill(' ');
      
      if(check == 1)
        cout<<"Cache Hit\n"<<"Line of Index = "<<index<<" found with Tag:-"<<tag<<"\n\n";
      else if(check == 3)
        cout<<"Cache Miss\n"<<"Line of Index = "<<index<<" not found\n\n";
      else 
        cout<<"Cache Miss\n"<<"Line of Index = "<<index<<" found but Tag:- "<<tag<<" does not match\n\n";

      cout<<"Total Hit rate:- Total Miss rate:-\n";
      cout<<((float)(hits)/(float)(hits + misses))*100<<"%\t"<<((float)(misses)/(float)(hits + misses))*100<<"\n";
    }
};


