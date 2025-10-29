/*
    Given two arrays sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) 
    and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). 
    
    Return the number of students that are unable to eat.
*/

/**
 * @param {number[]} students
 * @param {number[]} sandwiches
 * @return {number}
 */
var countStudents = function (students, sandwiches) {
    // still someone want the top sandwich
    while (students.includes(sandwiches[0])) {
        if (students[0] === sandwiches[0]) {
            students.shift();
            sandwiches.shift();
        } else {
            const s = students.shift();
            students.push(s);
        }
    }

    return students.length;
};