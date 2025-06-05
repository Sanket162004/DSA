class Solution {
public:
    // Check columns for duplicates
    bool column_check(vector<vector<char>>& board)
    {
        for (int col = 0; col < 9; col++) 
        {
            unordered_set<char> seen;  // Track digits seen in this column

            for (int row = 0; row < 9; row++) 
            {
                char val = board[row][col];
                if (val != '.')  // Ignore empty cells
                {
                    if (seen.find(val) != seen.end()) 
                    {
                        // Duplicate digit found in this column ❌
                        return false;
                    }
                    seen.insert(val);  // Mark digit as seen ✅
                }
            }
        }
        return true;  // No duplicates in any column ✅
    }

    // Check rows for duplicates
    bool row_check(vector<vector<char>>& board)
    {
        for (int row = 0; row < 9; row++) 
        {
            unordered_set<char> seen;  // Track digits seen in this row

            for (int col = 0; col < 9; col++) 
            {
                char val = board[row][col];
                if (val != '.')  // Ignore empty cells
                {
                    if (seen.find(val) != seen.end()) 
                    {
                        // Duplicate digit found in this row ❌
                        return false;
                    }
                    seen.insert(val);  // Mark digit as seen ✅
                }
            }
        }
        return true;  // No duplicates in any row ✅
    }

    // Check 3x3 sub-boxes for duplicates
    bool three_by_three_check(vector<vector<char>>& board)
    {
        // Each sub-box starts at row: 0, 3, 6 and col: 0, 3, 6
        for (int box_row = 0; box_row < 9; box_row += 3) 
        {
            for (int box_col = 0; box_col < 9; box_col += 3) 
            {
                unordered_set<char> seen;  // Track digits in this 3x3 box

                // Traverse all cells inside this 3x3 box
                for (int r = box_row; r < box_row + 3; r++) 
                {
                    for (int c = box_col; c < box_col + 3; c++) 
                    {
                        char val = board[r][c];
                        if (val != '.')  // Ignore empty cells
                        {
                            if (seen.find(val) != seen.end()) 
                            {
                                // Duplicate digit found in this 3x3 box ❌
                                return false;
                            }
                            seen.insert(val);  // Mark digit as seen ✅
                        }
                    }
                }
            }
        }
        return true;  // No duplicates in any 3x3 box ✅
    }

    // Main validation function
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        // Check 3x3 boxes, rows, and columns
        bool validBoxes = three_by_three_check(board);
        bool validRows = row_check(board);
        bool validColumns = column_check(board);

        // Return true only if all checks passed
        return validBoxes && validRows && validColumns;
    }
};