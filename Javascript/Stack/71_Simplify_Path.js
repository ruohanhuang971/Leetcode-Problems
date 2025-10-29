/*
    Given an absolute path
    Transform path into its simplified canonical path.
*/

/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function (path) {
    const pathArr = path.split('/');

    const stack = [];
    for (const n of pathArr) {
        if (n === '..' && stack.length > 0) {
            // pop if go to parent dir
            stack.pop();
        } else if (n !== '.' && n !== '' && n !== '..') {
            // push to stack dir names
            stack.push(n);
        }
    }
    return ('/' + stack.join('/'))
};