pub struct Matrix {
    pub rows: usize,
    pub cols: usize,
    pub data: Vec<f64>,
}

impl Matrix {
    pub fn new(rows: usize, cols: usize) -> Matrix {
        Matrix {
            rows,
            cols,
            data: vec![0.0; rows * cols],
        }
    }

    pub fn get(&self, row: usize, col: usize) -> f64 {
        self.data[row * self.cols + col]
    }

    pub fn set(&mut self, row: usize, col: usize, val: f64) {
        self.data[row * self.cols + col] = val;
    }
}

fn lu_dcp(mat: &Matrix) -> (Matrix, Matrix) {
    // TODO: Raise error if mat is not square
    let mut l = Matrix::new(mat.rows, mat.cols);
    let mut u = Matrix::new(mat.rows, mat.cols);

    for i in 0..mat.rows {
        l.set(i, i, 1.0);
    }

    for i in 0..mat.rows {
        for j in 0..mat.cols {
            if i <= j {
                u.set(i, j, mat.get(i, j));
                for k in 0..i {
                    u.set(i, j, u.get(i, j) - l.get(i, k) * u.get(k, j));
                }
            } else {
                l.set(i, j, mat.get(i, j));
                for k in 0..j {
                    l.set(i, j, l.get(i, j) - l.get(i, k) * u.get(k, j));
                }
                l.set(i, j, l.get(i, j) / u.get(j, j));
            }
        }
    }

    (l, u)
}

fn print_mat(mat: &Matrix) {
    for i in 0..mat.rows {
        for j in 0..mat.cols {
            print!("{} ", mat.get(i, j));
        }
        println!();
    }
}

fn main() {
    let mut a: Matrix = Matrix::new(3, 3);
    let data = vec![2, -1, 0, -1, 2, -1, 0, -1, 2];

    println!("Matrix a:");
    print_mat(&a);

    for i in 0..a.rows {
        for j in 0..a.cols {
            a.set(i, j, data[i * a.cols + j] as f64);
        }
    }
    println!("Matrix a:");
    print_mat(&a);

    let (l, u) = lu_dcp(&a);

    println!("Matrix l:");
    print_mat(&l);

    println!("Matrix u:");
    print_mat(&u);
}
