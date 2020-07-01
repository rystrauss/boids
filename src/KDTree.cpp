//
// Created by Ryan Strauss on 6/30/20.
//

#include <cmath>
#include "KDTree.h"


Node::Node(Boid *boid, bool vertical, const Node::NodePtr &left, const Node::NodePtr &right) {
    this->boid = boid;
    this->vertical = vertical;
    this->left = left;
    this->right = right;
}

Node::~Node() = default;

bool Node::isLeaf() const {
    return this->left == nullptr && this->right == nullptr;
}

KDTree::KDTree() {
    this->root = nullptr;
}

Node::NodePtr KDTree::insert(const Node::NodePtr &node, Boid *boid, bool vertical) {
    if (node == nullptr) {
        return std::make_shared<Node>(boid, vertical, nullptr, nullptr);
    }

    if ((node->vertical && boid->position.x < node->boid->position.x) ||
        (!node->vertical && boid->position.y < node->boid->position.y)) {
        node->left = insert(node->left, boid, !node->vertical);
    } else {
        node->right = insert(node->right, boid, !node->vertical);
    }

    return node;
}

void KDTree::insert(Boid *boid) {
    root = insert(root, boid, true);
}

double distance2(const Boid *boid, const Node::NodePtr &node) {
    return std::pow((boid->position.x - node->boid->position.x), 2) +
           std::pow((boid->position.y - node->boid->position.y), 2);
}

void KDTree::search(Boid *query, double radius, const Node::NodePtr &node, std::vector<Boid *> &results) const {
    if (node->isLeaf()) {
        if (distance2(query, node) < radius * radius) {
            results.push_back(node->boid);
        }
        return;
    }

    double w = distance2(query, node);

    if (w < radius * radius)
        results.push_back(node->boid);

    double qx = query->position.x;
    double nx = node->boid->position.x;
    double qy = query->position.y;
    double ny = node->boid->position.y;

    if (node->vertical) {
        if (qx < nx) {
            if (qx - radius <= nx && node->left != nullptr) {
                search(query, radius, node->left, results);
            }
            if (qx + radius > nx && node->right != nullptr) {
                search(query, radius, node->right, results);
                return;
            }
        } else {
            if (qx + radius > nx && node->right != nullptr) {
                search(query, radius, node->right, results);
            }
            if (qx - radius <= nx && node->left != nullptr) {
                search(query, radius, node->left, results);
                return;
            }
        }
    } else {
        if (qy < ny) {
            if (qy - radius <= ny && node->left != nullptr) {
                search(query, radius, node->left, results);
            }
            if (qy + radius > ny && node->right != nullptr) {
                search(query, radius, node->right, results);
                return;
            }
        } else {
            if (qy + radius > ny && node->right != nullptr) {
                search(query, radius, node->right, results);
            }
            if (qy - radius <= ny && node->left != nullptr) {
                search(query, radius, node->left, results);
                return;
            }
        }
    }
}

std::vector<Boid *> KDTree::search(Boid *query, double radius) const {
    std::vector<Boid *> results;
    search(query, radius, root, results);
    return results;
}
