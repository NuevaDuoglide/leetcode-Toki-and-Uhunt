/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    // Mengembalikan langsung nilai panjang
    return args.length;
};