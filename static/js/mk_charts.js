function getColor(percent) {
	let color = '';

	if (percent > 0 && percent <= 25) color = '#AADEA7';
	else if (percent > 25 && percent <= 35) color = '#FEBB61';
	// else if (percent > 50 && percent <= 75) color = '#F66D44';
	else if (percent > 35 && percent <= 100) color = '#F66D44';
	else color = '#2F4F4F';
	// console.log(color);
	return color;
}

const circle = new CircularProgressBar('pie');
circle.initial();
