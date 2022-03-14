
`for method 1`
```c++
	for (vfc::uint8_t i = 0U; i < polyline.m_numPoints; ++i)
	{
		const auto isPolypointExceeding =
			isPolypointInFrontAndExceedingStandardDeviationThreshold(polyline.m_points[i]);

		if (isPolypointExceeding)
		{
			firstIndex = i;
			break;
		}
	}
```

`for method 2`
```c++
   for (InputDefines::ObstacleSensors::PtrSpan::const_iterator iter = span.begin(); iter != span.end();
        ++iter)
   {
      returnList.push_back(*iter);
      if (returnList.size() == returnList.capacity())
         break;
   }
```

`for method 3`
```c++
    for (const auto& point : container)
```