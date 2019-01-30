# SharedString
Console output. Switch to raw view mode for better display.

Object creation for s1 [abc]
Constructor-1 called
NOT Found in map. Doing fresh allocation

Object creation for s2 [abc]
Constructor-1 called
Found in map! Not allocating new memory

Object creation for s3 [def]
Constructor-1 called
NOT Found in map. Doing fresh allocation

Object creation for s4 [ghi]
Constructor-1 called
NOT Found in map. Doing fresh allocation

Object creation for s5 [def]
Constructor-1 called
Found in map! Not allocating new memory

Object creation for s6 by copying
Copy constructor called!
searching [def]...

Object creation for s7 by assignment
Constructor-0 called
Assignment operator called!

s1: abc, address: 0x0066FF40
s2: abc, address: 0x0066FF40
s3: def, address: 0x0066AA38
s4: ghi, address: 0x0066B5F8
s5: def, address: 0x0066AA38
s6: def, address: 0x0066AA38
s7: def, address: 0x0066AA38

--------------------------------------------
Displaying Stats:
--------------------------------------------
abc: 2
def: 4
ghi: 1
--------------------------------------------

--------------------------------------------
Destructor calls:
--------------------------------------------
Destructor called
Reducing reference count for [abc] to: 1
Destructor called
Freeing memory for [abc]... [DONE]
Destructor called
Reducing reference count for [def] to: 3
Destructor called
Freeing memory for [ghi]... [DONE]
Destructor called
Reducing reference count for [def] to: 2
Destructor called
Reducing reference count for [def] to: 1
Destructor called
Freeing memory for [def]... [DONE]
--------------------------------------------
