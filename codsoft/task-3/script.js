let currentResult = '';

function appendToResult(value) {
    currentResult += value;
    document.getElementById('result').value = currentResult;
}

function calculateResult() {
    try {
        currentResult = eval(currentResult);
        document.getElementById('result').value = currentResult;
    } catch (error) {
        document.getElementById('result').value = 'Error';
    }
}

function clearResult() {
    currentResult = '';
    document.getElementById('result').value = '';
}
