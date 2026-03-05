use rand::Rng;

struct Processor {
    data: Vec<i32>
}

impl Processor {

    fn new(size: usize) -> Self {
        let mut rng = rand::thread_rng();
        let mut d = Vec::new();

        for _ in 0..size {
            d.push(rng.gen_range(0..100000));
        }

        Processor { data: d }
    }

    fn transform(&self, mut x:i32) -> i32 {
        for i in 0..30 {
            x = (x * 19 + i) ^ (x >> 2);
            x = x % 90000;
            if x < 0 { x = -x; }
        }
        x
    }

    fn compute(&self) -> i32 {
        let mut sum = 0;

        for v in &self.data {
            sum += self.transform(*v);
        }

        sum
    }

    fn expand(&mut self) {
        let mut extra = Vec::new();

        for v in &self.data {
            extra.push(self.transform(*v));
        }

        self.data.extend(extra);
    }
}

fn main() {
    let mut p = Processor::new(600);
    p.expand();
    println!("{}", p.compute());
}