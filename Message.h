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

Message::Message(const Message &M):contents(m.contents),folders(m.folders)
{
  put_Msg_in_Folders(folders);
}
Message& Message::operator=(const Message& rhs)
{
  if( &rhs != this)
    remove_Msg_from_Folder();
  contents = rhs.contents;
  folders = rhs.folders;
  put_Msg_in_Folders(rhs.folders);
}
void Message::put_Msg_in_Folders(const set<Folder*> &rhs)
{
  for( set<Folder*>::const_iterator beg = rhs.begin();
       beg != rhs.end();
       ++beg;)
       (*beg) -> addMsg(this);
}
void M
