/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function (height) {
    let ans = 0;
     
    const lm = [];
    const rm = new Array(height.length);
    
    let l = -Infinity;
    let r = -Infinity;
    // left 
    for(let val of height){
        l = Math.max(l,val);
        lm.push(l);
    }

    // right
    for(let i=height.length-1;i>=0;i--){
        r = Math.max(r,height[i]);
        rm[i] = r;
    }

    for(let i=0;i<height.length;i++){
        let sum = Math.min(lm[i],rm[i])-height[i];
        ans+=sum;
    }
    return ans;
};