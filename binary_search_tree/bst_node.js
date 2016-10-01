const BSTNode = function (val) {
  this.val = val;
  this.left = null;
  this.right = null;
};

BSTNode.prototype.insertVal = function (val) {
  if (val < this.val) {
    if (this.left) {
      this.left.insertVal(val);
    } else {
      this.left = new BSTNode(val);
    }
  } else if (val > this.val) {
    if (this.right) {
      this.right.insertVal(val);
    } else {
      this.right = new BSTNode(val);
    }
  }
};

BSTNode.prototype.show = function () {
  if (this.left) { this.left.show(); }
  console.log(this.val);
  if (this.right) { this.right.show(); }
};

growTree = function (node) {
  if (node.left || node.right) {
    const left = node.left ? growTree(node.left) : undefined;
    const right = node.right ? growTree(node.right) : undefined;
    return [left, node.val, right];
  } else {
    return node.val;
  }
};

showRow = function (arr) {
  console.log("  " + arr[1] + "  ");
  console.log(showRow(arr[0]) + " " + showRow(arr[2]));
}

BSTNode.prototype.showTree = function () {
  const thisTree = growTree(this);
};



const root = new BSTNode(5);
root.insertVal(2);
root.insertVal(6);
root.insertVal(3);
root.insertVal(4);

root.showTree();
