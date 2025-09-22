# CategoryPrioritization
UnrealEngine plugin that allows you to bring specific categories to the top of the object details panel.

## Usage
Declare in class metadata:
```
UCLASS(PrioritizeCategories = ("Settings", "State"))
```
then the properties in the specified categories will be brought to the top of details panel.
```
UPROPERTY(Category = "Settings|Character")
```
Also you can specify the highest priority categories in editor preference settings.
