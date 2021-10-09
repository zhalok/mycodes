/**
 * @param {string[]} nums
 * @param {string} target
 * @return {number}
 */
var numOfPairs = function (nums, target) {
    let ans = [];
    for (let i = 0; i < nums.length; i++)
        for (let j = 0; j < nums.length; j++)
            if (i != j && (nums[i] + nums[j]) === target)
                ans.push([i, j]);

    return ans.length;
};

// const ans = numOfPairs(["777", "7", "77", "77"], "7777");
// console.log(ans);