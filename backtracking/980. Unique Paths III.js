/**
 * @param {number[][]} grid
 * @return {number}
 */
var uniquePathsIII = function(grid) {
    let m = grid.length;
    let n = grid[0].length;

    
    let ot = 0;
    for (let v1 of grid) {
        for (let val of v1) {
            if (val === 0) ot++;
        }
    }

    let ans = 0;
    let o = 0; 
    function solve(r, c) {
        
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] === -1 || grid[r][c] === 10) {
            return;
        }

       
        if (grid[r][c] === 2) {
            if (o === ot+1) ans++; 
            return;
        }

       
        let val = grid[r][c];
        grid[r][c] = 10;
        o++;

        solve(r - 1, c);
        solve(r + 1, c);
        solve(r, c - 1);
        solve(r, c + 1);

       
        grid[r][c] = val;
        o--;
    }

    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                solve(i, j);
            }
        }
    }

    return ans;
};
