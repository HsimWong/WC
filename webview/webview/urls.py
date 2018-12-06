"""webview URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/2.0/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
# from django.contrib import admin
# from django.urls import path

# urlpatterns = [
#     path('admin/', admin.site.urls),
# ]

from django.conf.urls import url
 
from . import view 
from . import search
 
urlpatterns = [
	url(r'^$', view.first),
    url(r'hello', view.hello),
    url(r'^search-form$', search.search_form),
    url(r'^search$', search.search),
    url(r'^matches', view.matches),
    url(r'^teams', view.teams),
    url(r'^groups', view.groups),
    url(r'^score_rank', view.score_rank),
    url(r'^players',view.players)
]