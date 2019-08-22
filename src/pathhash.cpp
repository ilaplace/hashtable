//This code uses hash tables to lookup for paths
#include <iostream>
#include <unordered_map>
#include "datastructures.h"


struct Point{
    int x, y;

    Point(int init, int fin) :x(init), y(fin){}

    bool operator==(const Point& p) const{
        return p.x == x && p.y == y;
    }
};

struct Path {
    Point start_point, final_point;

    Path(Point start, Point final) :start_point(start), final_point(final){}

friend bool operator==(const Path& p1, const Path& p2){
        return p1.start_point == p2.start_point && p1.final_point == p2.final_point;
    }
};

class Hash{
    public:
     size_t operator()(const Path& p) const{
        std::size_t h1 = std::hash<int>()(p.start_point.x);
        std::size_t h2 = std::hash<int>()(p.final_point.x);
        std::size_t h3 = std::hash<int>()(p.start_point.y);
        std::size_t h4 = std::hash<int>()(p.final_point.y);
        return (h1)^(h2)^(h3)^(h4);
    };
};

int main(int argc, char const *argv[])
{
    Point init(0,0), fin(2,3);
    Path path (init, fin);
    
    Point init2(0,0), fin2(2,3);
    Path path2 (init2, fin2);

    std::unordered_multimap<Path, int,Hash> ummap;
    std::unordered_map<Path,int, Hash> umap;
    ummap.insert(std::make_pair(path,1));
    ummap.insert(std::make_pair(path,2));
    //This is in nomal unordered map
    //ummap[path2] = 2;

    auto it = ummap.find(path);

    //std::cout << umap.bucket_size(1) << std::endl;

    for (it = ummap.begin(); it !=ummap.end(); it++)
    {
        std::cout << it->second<< std::endl;
    }
    
    return 0;
}
