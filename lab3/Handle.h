//: C05:Handle.h 
// Handle classes 
#ifndef HANDLE_H 
#define HANDLE_H 
 
class Handle { 
  struct Cheshire; // Class declaration only 
  Cheshire* smile; 
public: 
  Handle(); //replaced initialize
  ~Handle(); //replaced cleanup
  int read(); 
  void change(int); 
}; 
#endif // HANDLE_H ///:~ 