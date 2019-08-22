/*unordered map is used to implement hash tables. It store key, value pairs. For every key value, a hash function is computed and value is stored at that hash entry. 
params: key type, mapped value*/

#include <iostream>
#include <unordered_map>

using namespace std;

struct Person
{
    string first, last;

    Person(string f, string l){
        first =f;
        last =l;
    }
    /*So that two same people would be equal */
    bool operator==(const Person& p) const{
        return first == p.first && last == p.last;
    }
};

/*Hash function is defined as XOR of the hash values */
class MyHashFunction{
public:
    size_t operator()(const Person& p) const{
        return (hash<string>()(p.first))^(hash<string>()(p.last));
    }
};



int main(int argc, char const *argv[])
{
    /* With standard data types
    unordered_map<string, double> umap;
    umap["PI"] = 3.14; 
    string key = "PI";
    auto it = umap.find(key);
    cout<< it->second;
     */

    unordered_map<Person, int, MyHashFunction> um; 
    Person p1("ismail", "uzdenov"); 
    Person p2("Ram", "Singh"); 
    Person p3("Laxman", "Prasad"); 
  
    um[p1] = 1; 
    um[p2] = 2; 
    um[p3] = 3;

    auto it = um.find(p2);
    cout << it->second;

}

