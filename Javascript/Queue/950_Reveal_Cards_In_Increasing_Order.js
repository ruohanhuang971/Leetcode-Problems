/**
 * @param {number[]} deck
 * @return {number[]}
 */
var deckRevealedIncreasing = function (deck) {
    const ans = [];
    deck.sort((a, b) => b - a);

    for (let i = 0; i < deck.length; i++) {
        if (ans.length > 0) {
            ans.unshift(ans[ans.length - 1]);
            ans.pop();
        }
        ans.unshift(deck[i]);
    }

    return ans;
};