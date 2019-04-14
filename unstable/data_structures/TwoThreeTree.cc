#include <iostream>
#include <optional>
using namespace std;

struct TTNode {
  bool hasTwoChildren = true;
  int lData, rData;
  TTNode* lChild = nullptr;
  TTNode* mChild = nullptr;
  TTNode* rChild = nullptr;

  TTNode() = default;
  TTNode(int data) : lData(data) {}
  TTNode(int ldata, int rdata)
      : hasTwoChildren(false), lData(ldata), rData(rdata) {}

  bool isLeaf() const {
    return (hasTwoChildren)
               ? lChild == nullptr && rChild == nullptr
               : lChild == nullptr && mChild == nullptr && rChild == nullptr;
  }

  bool valueEqual(const int target) {
    if (hasTwoChildren) {
      return lData == target;
    } else {
      return lData == target || rData == target;
    }
  }
};

class TwoThreeTree {
  TTNode* root = nullptr;

 private:
  void inorderHelper(TTNode* node) {
    if (node->isLeaf()) {
      if (node->hasTwoChildren) {
        cout << node->lData << " ";
      } else {
        cout << node->lData << " " << node->rData << " ";
      }
    } else if (node->hasTwoChildren) {
      inorderHelper(node->lChild);
      cout << node->lData << " ";
      inorderHelper(node->rChild);
    } else {
      inorderHelper(node->lChild);
      cout << node->lData << " ";
      inorderHelper(node->mChild);
      cout << node->rData << " ";
      inorderHelper(node->rChild);
    }
  }

  std::optional<int> findHelper(TTNode* node, const int& target) {
    if (node->valueEqual(target))
      return target;

    if (node->isLeaf()) {
      return {};
    } else if (node->hasTwoChildren) {
      if (target < node->lData)
        return findHelper(node->lChild, target);
      return findHelper(node->rChild, target);
    } else {
      if (target < node->lData)
        return findHelper(node->lChild, target);
      else if (target < node->rData)
        return findHelper(node->mChild, target);
      else
        return findHelper(node->rChild, target);
    }
  }

  TTNode* findPreviousNode(TTNode* node, const int& target) {
    if(node->isLeaf()){
      
    }
  }

  void treeSplit() {}
  void treeFix() {}

 public:
  bool isEmpty() const { return root == nullptr; }
  bool find(int target) {
    if (isEmpty()) {
      return false;
    } else {
      if (auto t = findHelper(this->root, target)) {
        return t == target;
      }
      return false;
    }
  }
  bool insert(int target) { return false; }
  bool remove(int target) { return false; }
  void inorderTraverseAndPrint() {
    if (this->root) {
      inorderHelper(this->root);
    } else {
      cout << "INFO: Empty 2-3-Tree" << endl;
    }
  }

  void debugInitTree() {
    /*
                    (50)
            (30)          (70,90)
      (10,20)  (40)    (60) (80) (100)
    */
    root = new TTNode(50);
    root->lChild = new TTNode(30);
    root->rChild = new TTNode(70, 90);
    root->lChild->lChild = new TTNode(10, 20);
    root->lChild->rChild = new TTNode(40);
    root->rChild->lChild = new TTNode(60);
    root->rChild->mChild = new TTNode(80);
    root->rChild->rChild = new TTNode(100);
  }
};

int main() {
  TwoThreeTree t;
  t.debugInitTree();
  cout << "\n@test inorderTraverse:\n";
  t.inorderTraverseAndPrint();
  cout << '\n' << boolalpha;
  cout << "\n@test find:\n";
  cout << "finding 50: \t\t" << t.find(50) << '\n';
  cout << "finding 70: \t\t" << t.find(70) << '\n';
  cout << "finding 20: \t\t" << t.find(20) << '\n';
  cout << "finding 100: \t\t" << t.find(100) << '\n';
  cout << "finding 140(Nonexist): \t" << t.find(140) << '\n';
  return 0;
}
