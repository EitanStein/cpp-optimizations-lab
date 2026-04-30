- lifetime class for testing when objects actually die and whether something like RVO, std::move operates properly
- based on the lifetime  class + examples in Jason Turner's videos (C++ weekly with Jason Turner)


- using std::move in the same function to 'move' data does not mean less constructions/destructions
- move using RVO will mean less constructions/destructions