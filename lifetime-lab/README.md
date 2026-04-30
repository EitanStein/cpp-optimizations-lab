- lifetime class for testing when objects actually die and whether something like RVO, std::move operates properly
- based on the lifetime  class + examples in Jason Turner's videos (C++ weekly with Jason Turner)


- using std::move in the same function to 'move' data does not mean less constructions/destructions
- move using RVO will mean less constructions/destructions

- expected/optional/tuple/variant and more construction and sending to RVO can be tricky
- - "return Liftime{}" will create an object, move construct to return value and destruct it
- - "return {}" using emplace ctor will only construct once (and destruct once later for the caller)