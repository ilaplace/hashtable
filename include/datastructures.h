#include <unordered_map>
#include <vector>

namespace MotionPrimitives{

    struct State{
        int x, y;

        State(int init, int fin) :x(init), y(fin){}

        bool operator==(const State& p) const{
            return p.x == x && p.y == y;
        }
    };

    class Motion{
        public: 
        State * state{ nullptr};
        Motion * parent{ nullptr};

    };

    template<typename _T>
    class Trajectory{
        public:
        void add(const _T &data){
            data_.push_back(data);
        }
        void add(const std::vector<_T> &data){
            data_.insert(data_.end(), data.begin(),data.end());
        }
        std::vector<_T> data_;
        bool flag_;
        int cost_;

    };


struct PathKey {
    State start_point, final_point;

    PathKey(State start, State final) :start_point(start), final_point(final){}

friend bool operator==(const PathKey& p1, const PathKey& p2){
        return p1.start_point == p2.start_point && p1.final_point == p2.final_point;
    }
};

class Hash{
    public:
     size_t operator()(const PathKey& p) const{
        std::size_t h1 = std::hash<int>()(p.start_point.x);
        std::size_t h2 = std::hash<int>()(p.final_point.x);
        std::size_t h3 = std::hash<int>()(p.start_point.y);
        std::size_t h4 = std::hash<int>()(p.final_point.y);
        return (h1)^(h2)^(h3)^(h4);
    };
};
   
}
