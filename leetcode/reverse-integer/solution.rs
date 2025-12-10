impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut is_neg = false;
        let mut x = if (x < 0) {
            is_neg = true;
            match x.checked_mul(-1) {
                None => return 0,
                Some(val) => val
            }
        } else {
            x
        };

        if (x == 0) { return 0 };

        let mut vec = Vec::new();
        while (x > 0) {
            vec.push(x % 10);
            x = x / 10;  
        }

        vec.reverse();
        let mut out = vec[0];
        let mut mul = 1i32;
        for val in &vec[1..] {
            mul = match mul.checked_mul(10) {
                Some(x) => x,
                None => { return 0; }
            };

            let inc = match val.checked_mul(mul) {
                Some(x) => x,
                None => { return 0; }
            };

            out = match out.checked_add(inc) {
                Some(x) => x,
                None => { return 0; }
            }
        }

        return if is_neg { -out } else { out };
    }
}
