//cmd+b -> open/close sidebar in vscode
#include <iostream>
#include "datastructures.h"

using namespace MotionPrimitives;

MotionPrimitives::Trajectory<Motion> createDummyTrajecory(){

     //Create and add the initial state
    MotionPrimitives::Motion *motion = new MotionPrimitives::Motion;
    MotionPrimitives::State *s = new MotionPrimitives::State(0,0);
    motion->state = s; 
    MotionPrimitives::Trajectory<Motion> tr;
    tr.add(*motion);

    //Create and add and intermiadieary state
    MotionPrimitives::Motion *motion2 = new MotionPrimitives::Motion;
    MotionPrimitives::State *s2 = new MotionPrimitives::State(1,1);
    motion->state = s; 
    tr.add(*motion2);

    //Create and add the final state
    MotionPrimitives::Motion *motion3 = new MotionPrimitives::Motion;
    MotionPrimitives::State *s3 = new MotionPrimitives::State(2,2);
    motion->state = s3; 

    tr.add(*motion3);

    tr.flag_ = true;
    tr.cost_ = 5;

    return tr;
}

 int main(int, char**) {
    
   auto tr = createDummyTrajecory();
   std::unordered_multimap<MotionPrimitives::PathKey,MotionPrimitives::Trajectory<Motion>, MotionPrimitives::Hash> umap;

    State init(0,0), fin(2,2);
    PathKey path (init, fin);

    //insert the path
    umap.insert(std::make_pair(path,tr));

    //find the path starts from 0,0 and goes to 2,2
    auto it = umap.find(path);

       for (it = umap.begin(); it !=umap.end(); it++)
    {
        std::cout << it->second.cost_<< std::endl;
    }


}