/*

int val = 2;                        // lvalue = rvalue
int* ptr = 0x02248847;              // lvalue = rvalue
vector<int> v1{1,2,3};              // same as v1 = {1,2,3}, lvalue = rvalue

auto v4 = v1 + v2;                  // lvalue = rvalue (v1+v2 is temporary)
v1 += v4;                           // lvalue += lvalue
size_t size = v.size();             // lvalue = rvalue
val = static_cast<int>(size);       // lvalue = rvalue(due to cast)
v1[1] = 4*i;                        // lvalue = rvalue
ptr = &val;                         // lvalue = rvalue
v1[2] = *ptr;                       // lvalue = lvalue

============================================================

auto& ptr2 = ptr;           // ptr2 is an l-value reference
auto&& v4 = v1 + v2;        // v4 is an r-value reference : && extends rvalue's life
                                (ref rval = rval)
auto& ptr3 = &val;          // ERROR : can't bind lvalue ref to rvalue
                                (ref lval =/= rval)
auto&& val2 = val;          // ERROR : can't bind rvalue ref to lvalue
                                (ref rval =/= lval)
const auto& ptr3 = ptr + 5; // OKAY : CAN bind const lvalue ref to rvalue (WHY?)
                                (const ref lval = rval)

============================================================

THIS MAKES THE PROBLEMS:

void nocos_Lref(vector<int>& v);
void const_Lref(const vector<int>& v);
void nocos_Rref(vector<int>&& v);

vector<int> v1 = v2 + v3;       // lval = rval
nocos_Lref(v1);                 // 
nocos_Rref(v1);                 // ERROR : passing lval to ref rval
nocos_Lref(v2 + v3);            // ERROR : passing rval to ref lval
const_Lref(v2 + v3);            //
nocos_Rref(v2 + v3);            //
                                // This is because rval cannot be changed.


*/