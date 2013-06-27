#include <set>
#include <string>
using namespace::std;
using std::string;
#include "Folder.h"
class Message
{
 public:
  //folders is initialized to the empty set automatically
  Message(const string &str = ""):
    contents(str) {}
  
  Message(const Message&);
  Message& operator=(const Message&);
  ~Message();
  
  void save (Folder&);
  void remove(Folder&);
 private:
  string contents;
  set<Folder*> folders;
  
  void put_Msg_in_Folders(const set<Folder*>&);
  void remove_Msg_from_Folders();
}
