import matplotlib.pyplot as plt
# from matplotlib import style
import numpy as np
# style.use('ggplot')

class svm:
    def __init__(self, visualisation = True):
        self.visualisation = visualisation
        self.colors = {1: 'r', -1: 'b'}
        if self.visualisation:
            self.fig = plt.figure()
            self.ax = self.fig.add_subplot(1, 1, 1)

    def fit(self, data):
        self.data = data
        #{  ||w||: [w, b]  }
        optimisation_dict = {}

        transforms = [[1, 1],
                    [-1, 1],
                    [1, -1],
                    [-1, -1]]

        full_data = []
        for yi in self.data:
            for feature_data in self.data[yi]:
                for feature in feature_data:
                    full_data.append(feature)

        self.max_feature_value = max(full_data)
        self.min_feature_data = min(full_data)
        full_data = None

        step_size = [self.max_feature_value * 0.1,
                    self.max_feature_value * 0.01]
                    #  self.max_feature_value * 0.001]
        
        b_range_multiplier = 5
        b_multiple = 5
        latest_optimum = self.max_feature_value * 10

        for step in step_size:
            w = np.array([latest_optimum,latest_optimum])
            optimized = False
            while not optimized:
                for b in np.arange(-1*(self.max_feature_value*b_range_multiplier), 
                                self.max_feature_value*b_range_multiplier,
                                step*b_multiple):
                    for transormation in transforms:
                        w_t = w*transormation
                        found = True
                        #yi(xi.w+b) >= 1
                        for yi in self.data:
                            for xi in self.data[yi]:
                                if not yi*(np.dot(w_t, xi)+b) >= 1:
                                    found = False
                        if found:
                            optimisation_dict[np.linalg.norm(w_t)] = [w_t, b]
            if w[0] < 0:
                optimized = True
                print("optimised a step")
            else:
                w = w - step
        
        norms = sorted([n for n in optimisation_dict])
        opt_choice = optimisation_dict[norms[0]]

        # ||w|| : [w, b]
        self.w = opt_choice[0]
        self.b = opt_choice[1]
        latest_optimum = opt_choice[0][0] + step*2

    def predict(self, features):
        classification = np.sign(np.dot(np.array(features), self.w) + self.b)
        if classification != 0 and self.visualisation:
            self.ax.scatter(features[0], features[1], s = 200, c = self.colors[classification])
        return classification
    
    def visualize(self, features):
        [[self.ax.scatter(x[10], x[1], s = 100, color = self.colors[i]) for x in class_dict[i]] for i in class_dict]

        #hyperplane = x.w+b
        #v = x.w+b
        #positive_support_vector(psv) = 1
        #negative_support_vector(nsv) = -1
        #decision boundary(db) = 0

        def hyperplane(x, w, b, v):
            return(-w[0] * x - b + v) / w[1]
        datarange = (self.min_feature_data*0.9, self.max_feature_value*1.1)
        hyp_x_min = datarange[0]
        hyp_x_max = datarange[1]

        #(w.x+b) = 1
        #positive support vector hyperplane
        psv1 = hyperplane(hyp_x_min, self.w, self.b, 1)
        psv2 = hyperplane(hyp_x_max, self.w, self.b, 1)
        self.ax.plot([hyp_x_min, hyp_x_max],[psv1, psv2])

        #(w.x+b) = -1
        #negative support vector hyperplane
        nsv1 = hyperplane(hyp_x_min, self.w, self.b, -1)
        nsv2 = hyperplane(hyp_x_max, self.w, self.b, -1)
        self.ax.plot([hyp_x_min, hyp_x_max],[nsv1, nsv2])

        #(w.x+b) = 0
        #decision boundary
        db1 = hyperplane(hyp_x_min, self.w, self.b, 0)
        db2 = hyperplane(hyp_x_max, self.w, self.b, 0)
        self.ax.plot([hyp_x_min, hyp_x_max],[db1, db2])

        plt.show()


class_dict = {-1: np.array([[1, 5], [2, 7], [3, 7], [2, 5]]), +1: np.array([[7, 1],[8, -1], [7, 2]])}
svm1 = svm()
svm1.fit(data = class_dict)
svm1.visualize()