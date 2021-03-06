#include <iostream>
#include <assert.h>

int alertFailureCount;
int networkAlertStub(float celcius) {
	std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
	// Return 200 for ok
	// Return 500 for not-ok
	// stub always succeeds and returns 200
	if (celcius <= 200) {
		return 200;
	}
	else {
		return 500;
	}

}

int alertInCelcius(float farenheit) {
	float celcius = (farenheit - 32) * 5 / 9;
	int returnCode = networkAlertStub(celcius);
	if (returnCode != 200) {
		// non-ok response is not an error! Issues happen in life!
		// let us keep a count of failures to report
		// However, this code doesn't count failures!
		// Add a test below to catch this bug. Alter the stub above, if needed.
		alertFailureCount++;
	}
	return alertFailureCount;
}

int main() {
	alertInCelcius(303.6);
	std::cout << alertFailureCount << " alerts failed.\n";
	assert(alertFailureCount == 0);
	alertInCelcius(400.5);
	std::cout << alertFailureCount << " alerts failed.\n";
	assert(alertFailureCount == 1);
	std::cout << "All is well (maybe!)\n";
	return 0;
}
