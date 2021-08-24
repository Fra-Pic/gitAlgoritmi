

let utils = {
	min: (a, b) => {
		if (!a || !b) return 0;
		return (a.key < b.key) ? a : b;
	},
	isLeaf: (node) => {
		return (node.left === null && node.right === null);
	}
};

