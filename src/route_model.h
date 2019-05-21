#pragma once

#include <limits>
#include <cmath>
#include <unordered_map>
#include "model.h"
#include <iostream>

/*
Add a private vector of Node objects named m_Nodes. This will store all of the nodes from the Open Street Map data.
Add a public "getter" method SNodes. This method should return a reference to the vector of Nodes stored as m_Nodes.
*/

class RouteModel : public Model {

  public:
    class Node : public Model::Node {
      public:
        // Add public Node variables and methods here.
        
        Node(){}
        Node(int idx, RouteModel * search_model, Model::Node node) : Model::Node(node), parent_model(search_model), index(idx) {}
      
      private:
        // Add private Node variables and methods here.
        int index;
        RouteModel * parent_model = nullptr;
        
    };
    
    // Add public RouteModel variables and methods here.
    RouteModel(const std::vector<std::byte> &xml);  
    std::vector<Node> path; // This variable will eventually store the path that is found by the A* search.

    // CODE: The RouteModel Class - public getter function that returns the nodes
    auto & SNodes() { return m_Nodes; }

  private:
    // Add private RouteModel variables and methods here.
    // CODE: The RouteModel Class - Vector of nodes
    std::vector<Node> m_Nodes;
};
