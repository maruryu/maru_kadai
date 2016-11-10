//package pr2calc;
import java.io.*;

public class Matrix {

	public double m[][];
	public int numOfRow;
	public int numOfColumn;

	public Matrix(){
		this.numOfRow = 0;
		this.numOfColumn = 0;
	}

	public Matrix(double[][] input){
		this.numOfRow=input.length;
		this.numOfColumn = input[0].length;
		this.m = new double[this.getNumOfRow()][this.getNumOfColumn()];
		this.m = input;
	}
	public Matrix(double[] input){
		int i;
		this.numOfRow = 1;
		this.numOfColumn = input.length;
		this.m = new double[this.getNumOfRow()][this.getNumOfColumn()];
		for(i=0;i<this.numOfColumn;i++){
			this.m[0][i]=input[i];
		}
	}
	public Matrix(int row,int column){
		this.numOfRow=row;
		this.numOfColumn=column;
		this.m = new double[this.getNumOfRow()][this.getNumOfColumn()];
	}

	public int getNumOfRow(){
		return this.numOfRow;
    }

	public int getNumOfColumn(){
		return this.numOfColumn;
    }

	public double showsComponentOf(int rowIndex, int columnIndex){
    	if(rowIndex > this.numOfColumn || columnIndex > this.numOfColumn){
    		System.out.println("");
            System.exit(0);
        }
    	return this.m[getNumOfRow()][getNumOfColumn()];
    }

	public void display(){
		int i,j;
		for(i=0;i<this.numOfRow;i++){
			System.out.print("[");
			for(j=0;j<this.numOfColumn;j++){
				System.out.print(" " + this.m[i][j] + " ");
			}
			System.out.println( "]" );
		}
	}


	public double getInnerProduct(Matrix target){
		int i;
		double result=0;
		if(this.numOfColumn == 1){
			System.out.println("Aが列ベクトルなので内積を求められません");
			System.exit(0);
		}
		else if(this.numOfRow == 1 && target.numOfRow == 1 && this.numOfColumn == target.numOfColumn){
			for(i=0;i<this.numOfColumn;i++){
				result += this.m[0][i] * target.m[0][i];
			}
		}
		else if(this.numOfRow == 1 && target.numOfColumn == 1 && this.numOfColumn == target.numOfRow){
			for(i=0;i<this.numOfColumn;i++){
				result += this.m[0][i] * target.m[i][0];
			}
		}
		else{
			System.out.println("内積計算が可能な条件を満たしてません");
			System.exit(0);
		}
		return result;
	}

	public boolean multipliable(Matrix target){
		if(this.numOfColumn == target.numOfRow){
			return true;
        }
        else{
        	System.out.println("要素数が計算できる組み合わせとなってません．");
            return false;
        }
	}

    public Matrix multiplyMatrix(Matrix target){
    	int i,j,k;
    	Matrix result;
    	result = new Matrix(this.getNumOfRow(),target.getNumOfColumn());
    	for(i=0;i<this.getNumOfRow();i++){
    		for(j=0;j<target.getNumOfColumn();j++){
    			for(k=0;k<this.getNumOfColumn();k++){
    				result.m[i][j]+=this.m[i][k]*target.m[k][j];
    			}
    		}
    	}
    	return result;
    }


	public static void main(String[] args) {

		Matrix mat0,mat1,mat2;
		double[]
			v0 = {2.0, -3.0, 7.0},
			v1 = {-1.0, -2.0, 2.0},
			n1 = {3,7,-5,2}
		;

		double[][]

			m0 = {
				{1.0, 2.0,  3.0},
				{3.0, 2.0, -1.0},
				{4.0, 2.0,  6.0}},

			m1 = {
				{ 5.0, 3.0, 1.0},
				{3.0, -3.0, 2}},

			n0 = {
				{3},
				{-2}},

			o0 = {
				{1,2,3},
				{3,2,-1},
				{4,2,6}},

			o1 = {
				{8,2},
				{-3,2},
				{1,6}},

			p0 = {
				{2,-3},
				{4,2}},

			p1 = {
				{-5,-3,1},
				{-3,3,2}},

			d;

		System.out.println("(1)");
                mat0 = new Matrix(v0);
                mat1 = new Matrix(v1);

		System.out.println("v0 = ");	mat0.display();
		System.out.println("v1 = ");	mat1.display();

		System.out.println("");
		System.out.println("v0 と v1 の内積は ");
		System.out.println(mat0.getInnerProduct(mat1) + "です");

		System.out.println("");
		System.out.println("(2)");
	        mat0 = new Matrix(m0);
	        mat1 = new Matrix(m1);

		System.out.println("m0 = ");	mat0.display();
		System.out.println("m1 = ");	mat1.display();

		System.out.println("");
		System.out.println("m0 * m1 = ");
		if(mat0.multipliable(mat1) == true)
			(mat0.multiplyMatrix(mat1)).display();

		System.out.println("");
		System.out.println("(3)");
	        mat0 = new Matrix(n0);
	        mat1 = new Matrix(n1);

		System.out.println("n0 = ");	mat0.display();
		System.out.println("n1 = ");	mat1.display();

		System.out.println("");
		System.out.println("n0 * n1 = ");
		if(mat0.multipliable(mat1) == true)
		(mat0.multiplyMatrix(mat1)).display();

		System.out.println("");
		System.out.println("(4)");
	        mat0 = new Matrix(o0);
	        mat1 = new Matrix(o1);

		System.out.println("o0 = ");	mat0.display();
		System.out.println("o1 = ");	mat1.display();

		System.out.println("");
		System.out.println("o0 * o1 = ");
		if(mat0.multipliable(mat1) == true)
			(mat0.multiplyMatrix(mat1)).display();

		System.out.println("");
		System.out.println("(5)");
	        mat0 = new Matrix(p0);
	        mat1 = new Matrix(p1);

		System.out.println("p0 = ");	mat0.display();
		System.out.println("p1 = ");	mat1.display();

		System.out.println("");
		System.out.println("p0 * p1 = ");
		if(mat0.multipliable(mat1) == true)
			(mat0.multiplyMatrix(mat1)).display();
	}
}