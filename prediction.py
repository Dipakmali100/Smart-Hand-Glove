import sys
import pandas as pd
from sklearn.neighbors import KNeighborsClassifier

# Step 1: Load the dataset
dataset = pd.read_csv('feeds.csv')  # Replace 'your_dataset.csv' with the path to your dataset

# Step 2: Separate features and target variable
X = dataset.iloc[:, :-1]  # Features
y = dataset.iloc[:, -1]   # Target variable

# Step 3: Initialize and train the classifier
knn_classifier = KNeighborsClassifier()
knn_classifier.fit(X, y)

# Step 4: Prepare the input data for prediction
input_data = pd.DataFrame([[float(sys.argv[1]), float(sys.argv[2]), float(sys.argv[3]), float(sys.argv[4])]])

# Step 5: Use the predict method of the classifier to make predictions
knn_predictions = knn_classifier.predict(input_data)

# Step 6: Print the predicted outputs
# print("KNN Predictions:", knn_predictions[0])
print(knn_predictions[0])

