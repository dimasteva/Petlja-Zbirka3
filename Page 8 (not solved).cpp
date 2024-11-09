/*
Task: Heirs

In a certain country, a king has taken the throne and started his royal lineage. He has numerous descendants, and each of them wants to know their position in the line of succession to the crown. The rule of succession states that the king is succeeded first by his oldest son. Next in line is the oldest grandson (if any), and so on. If a descendant has no children, then the next in line is his oldest brother, then his descendants, and so forth.  
Write a program that determines the order of succession for certain descendants of the king.

Input: The number \( n \) (1 ≤ \( n \) ≤ 50000), representing the total number of people in the king’s family tree (including him), is read from standard input. After that, pairs in the form "parent child" (each pair on a separate line, separated by a space) are entered, where children of the same parent are listed in descending order of age. Finally, the names of the descendants for whom the succession order is to be determined are entered (each on a separate line).

Output: For each descendant entered after the parent-child relationship description, print their succession position.

Example  
Input  
19  
Elisabeth Charles  
Elisabeth Andrew  
Elisabeth Edward  
Elisabeth Anne  
Charles William  
Charles Harry  
William George  
William Charlotte  
William Louis  
Anne Peter  
Anne Zara  
Andrew Beatrice  
Andrew Eugenie  
Edward James  
Edward Louise  
Peter Savannah  
Peter Isla  
Zara Mia  
Harry  
Charles  
Charlotte  
Louise  
James  
Isla  
Andrew  

Output  
Harry 6  
Charles 1  
Charlotte 4  
Louise 12  
James 11  
Isla 16  
Andrew 7
*/

