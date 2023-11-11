

let fibGenerator = function*() {
    let p = -1, q = 1, r = 0;
    while (true) {
        r = p + q;
        p = q;
        q = r;
        yield r;
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */

const gen = fibGenerator();
console.log(gen.next().value);
console.log(gen.next().value);
