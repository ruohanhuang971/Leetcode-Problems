/**
 * @param {string} senate
 * @return {string}
 */
var predictPartyVictory = function (senate) {
    const d = [];
    const r = [];
    for (let i = 0; i < senate.length; i++) {
        if (senate[i] === 'D') d.push(i);
        else r.push(i);
    }

    const n = senate.length;
    while (d.length > 0 && r.length > 0) {
        const senatorD = d.shift();
        const senatorR = r.shift();
        if (senatorD < senatorR) {
            // dire first
            d.push(n + senatorD);
        } else {
            r.push(n + senatorR);
        }
    }

    return (d.length === 0) ? "Radiant" : "Dire";
};