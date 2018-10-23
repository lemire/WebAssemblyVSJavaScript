function compute(d) {

    var start = 0, // incl
        end = d; // excl

    var byte_acc = 0,
        bit_num = 0,
        iter = 50,
        limit = 4;
    var buff = new ArrayBuffer(d * d / 8);

    (function() {
        var xd = 2 / d;
        var it = 0;
        for (var y = start; y < end; y++) {
            var yd = 2 * y / d - 1;
            for (var x = 0; x < d; x++) {

                var sum = doCalc(
                    xd * x - 1.5,
                    yd
                );

                byte_acc |= (sum <= limit);
                bit_num++;

                if (bit_num === 8) {
                    buff[it++] = byte_acc;
                    byte_acc = 0,
                        bit_num = 0;
                } else {
                    byte_acc <<= 1;
                }
            }
        }
    })();
   // console.log(buff);
    console.log('Fin du traitement');
}
function runmandelbrotJS(){
const d = 16000;
compute(d);
}

function doCalc(Cr, Ci) {
    var Zr = 0,
        Zi = 0,
        Tr = 0,
        iter = 50,
        limit = 4,
        Ti = 0;
    for (var i = 0; i < iter && Tr + Ti <= limit; i++) {
        Zi = 2 * Zr * Zi + Ci,
            Zr = Tr - Ti + Cr,
            Tr = Zr * Zr,
            Ti = Zi * Zi;
    }
    return Tr + Ti;
};
