const mySet = new Set();
mySet.add(2);
mySet.add(3);
mySet.add(2);
console.log(mySet);

const mySet1 = new Set();

mySet1.add({ ...{ a: 2, b: 3 } });
mySet1.add({ ...{ a: 2, b: 3 } });

console.log(mySet1);