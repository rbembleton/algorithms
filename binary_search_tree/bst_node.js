const BSTNode = function (val) {
  this.value = val;
  this.left = null;
  this.right = null;
};

BSTNode.prototype.insertVal = function (val) {
  if (val < this.value) {
    if (this.left) {
      this.left.insertVal(val);
    } else {
      this.left = new BSTNode(val);
    }
  } else if (val > this.value) {
    if (this.right) {
      this.right.insertVal(val);
    } else {
      this.right = new BSTNode(val);
    }
  }
};

BSTNode.prototype.show = function () {
  if (this.left) { this.left.show(); }
  console.log(this.value);
  if (this.right) { this.right.show(); }
};

BSTNode.prototype.showTree = function () {
  let firstRow = "";
  let secondRow = "";
  let leftThird = "";
  let rightThird = "";

  if (this.left) {
    const below = this.left.showTree();
    for (var i = 0; i < below.length; i++) {
      firstRow += " ";
      secondRow += " ";
    }
    secondRow += "/";
    leftThird = below;
  }
  firstRow += this.value;

  if (this.right) {
    const below = this.right.showTree();
    secondRow += "\\";
    for (var i = 0; i < below.length; i++) {
      firstRow += " ";
      secondRow += " ";
    }
    rightThird = below;
  }

  let leftArr = leftThird.split('\n');
  let rightArr = rightThird.split('\n');
  let thirdRow = "";

  leftArr.forEach((el, idx) => {
    thirdRow += leftArr[idx] + "  " + rightArr[idx] + '\n';
  });

  return firstRow + "\n" + secondRow + "\n" + thirdRow + "\n";
};

BSTNode.prototype.growTree = function () {

};



const root = new BSTNode(5);
root.insertVal(3);
root.insertVal(6);
// root.insertVal(4);

root.show();
console.log(root.showTree());
