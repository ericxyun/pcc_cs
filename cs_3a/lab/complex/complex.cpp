Complex::Complex()
{
	real = 0;
	imag = 0;
}

Complex::Complex(double real_part)
{
	real = real_part;
	imag = 0;
	
}

Complex::Complex(double real_part, 
		         double i)
{
	real = real_part;
	imag = i;
}

bool Complex::operator==(const Complex& ro) const
{
	if ((ro.real == this->real) &&
		(ro.imag == this->imag))
		return true;
	return false;
}

Complex Complex::operator+(const Complex& ro) const
{
	Complex sum;
	sum.real = this->real + ro.real;
	sum.imag = this->imag + ro.imag;
	return sum;
}

Complex Complex::operator-(const Complex& ro) const
{
	Complex difference;
	difference.real = this->real - ro.real;
	difference.imag = this->imag - ro.imag;
	return difference;
}

Complex Complex::operator*(const Complex& ro) const
{
	Complex product;
	product.real = (this->real * ro.real) - (this->imag * ro.imag);
	product.imag = (this->real * ro.imag) + (this->imag * ro.real);
	return product;
}

void Complex::display()
{
	cout << real << endl;
	cout << imag << endl;
}

